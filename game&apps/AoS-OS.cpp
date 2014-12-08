#if 0
AoS-OS.exe : AoS-OS.obj voxlap5.obj v5.obj kplib.obj winmain.obj cnet.obj objects.obj AoS-OS.cpp;
	link AoS-OS cnet objects voxlap5 v5 kplib winmain ddraw.lib dinput.lib ole32.lib dxguid.lib user32.lib gdi32.lib ws2_32.lib winmm.lib /opt:nowin98

AoS-OS.obj : AoS-OS.cpp voxlap5.h sysmain.h;
	cl /c /J /TP AoS-OS.cpp /Ox /Ob2 /G6Fy /Gs /ML /QIfist
cnet.obj : cnet.cpp cnet.h;
    cl /c /J /TP cnet.cpp /Ox /Ob2 /G6Fy /Gs /ML /QIfist
objects.obj : objects.cpp objects.h;
    cl /c /J /TP objects.cpp /Ox /Ob2 /G6Fy /Gs /ML /QIfist
voxlap5.obj: voxlap5.c voxlap5.h;
	cl /c /J /TP voxlap5.c   /Ox /Ob2 /G6Fy /Gs /ML
!if 0
#endif

/*

This is the base code that will be usued for testing
Voxlap functions and eventually be the starting point
for the Ace of Spades code

*/


#include "sysmain.h"
#include <math.h>
#include <stdio.h>
#include "voxlap5.h"
#include "cnet.h"
#include "objects.h"

CNet network;
static char wrkdir[MAX_PATH];
char address[20];
unsigned int mode;
long *vxlmap;

enum{
head,body,arm,leg,
nummodel};
const char kv6nam[] = {"playerhead.kv6,playertorso.kv6,\
playerarms.kv6,playerleg.kv6"};
kv6data *models[nummodel];

#define MAXSPRITES 365

enum {
ctr_quit,ctr_forward,ctr_back,ctr_left,ctr_right,ctr_jump,ctr_crouch,ctr_sneak,ctr_sprint,ctr_save_vxl,numctr
};
static char controlnames[] = "quit,forward,back,left,right,jump,crouch,sneak,sprint,save-vxl";
static int controls[numctr];

double curt, oldt;
float fsynctics;

#define RADIUS PI*2
#define PI2 PI*.4849
float mousex,mousey, rotx=0, roty=0;
long mouseb;

plrsprite ispr;

int netframe(){
    pckdata packet;

    int ret = network.check_packet(&packet);

    if(ret==0){
        if(mode==1){
            if(network.handle_packet(packet))
                return 2;
        }
    }else if(ret>1){
        return 1;
    }
    free(packet.data);
    return 0;
}

int loadmodels(){
	int i=0;
	char namtmp[40] = "kv6\\";
	char *namtmp2 = strtok((char*)kv6nam,",");
	while(namtmp2!=NULL){
		strcat(namtmp+3, namtmp2);
		models[i] = getkv6(namtmp);
		if(models==0)return 1;
		namtmp2 = strtok(NULL,",");
		i++;
	}
	if(i<nummodel)return 2;
	return 0;
}

int loadconfig(){
	int i=0;
	char *tmpnam = strtok(controlnames,",");
	char finpath[MAX_PATH];
	strcpy(finpath, wrkdir);
	strcat(finpath,"config.ini");
	while(tmpnam!=NULL){
		char ctrbuff[6];
		char msg[200];
		GetPrivateProfileString("controls",tmpnam,0,ctrbuff,6,finpath);
		
		controls[i] = strtol(ctrbuff, NULL, 16);
		if(controls[i]==0)return 1;
		
		tmpnam = strtok(NULL,",");
		i++;
	}
	if(i<numctr)return 2;
	return 0;
}

long initapp (long argc, char **argv){
	GetModuleFileName(NULL, wrkdir, MAX_PATH);
	for(int i=strlen(wrkdir);1;i--){
		if(wrkdir[i]=='\\'){
			wrkdir[i+1] = '\0';
			break;
		}
	}
	if(loadconfig()){
		MessageBox(ghwnd, "Failed to load configuration file", "", MB_OK);
		return -1;
	}/*else if(loadmodels()){
		MessageBox(ghwnd, "Failed to load kv6 models", "", MB_OK);
		return -2;
	}*/

    prognam = "AoS-OS";
	xres = 640; yres = 480; colbits = 32; fullscreen = 0;
    if(initvoxlap())return -3;

    vx5.fallcheck = 1;
	vx5.mipscandist = 69;
	vx5.maxscandist = 128;
	vx5.lightmode = 0;
	//setsideshades(0,64,32,32,16,48);

    vxlmap = (long*) malloc(VSID*VSID*sizeof(long));
    if(network.init())return -4;

    if(argc>1){
        strcpy(address, argv[1]);
		//getspr(&ispr.sprdata, "kv6\\playerhead.kv6");
		initializeplayer(&ispr);
        return 0;
    }
    MessageBox(ghwnd, "Supply me with an AoS address(server address, port, version)\nEx. aos://16777343:32887:0.75", "", MB_OK);

    return(-5);
}

void doframe (){	
    long frameptr, pitch, xdim, ydim;

    switch(mode){
        case 0:{ //Connecting to Host
            startdirectdraw(&frameptr, &pitch, &xdim, &ydim);
            voxsetframebuffer(frameptr, pitch, xdim, ydim);
            clearscreen(0);
            stopdirectdraw();
            nextpage();

            if(network.connect_host(address, 3)){
                quitloop();
                return;
            }
            mode = 1;
            return;
        }
        case 1:{ //Loading Map
            if(netframe()){
                quitloop();
                return;
            }
            if(network.netstatus==StatusConnected){
                network.disconnect_host(0);
				ispr.e.x = ispr.e.y = ispr.p.x = ispr.p.y = VSID*.5;
				ispr.e.z = ispr.p.z = getfloorz(ispr.p.x,ispr.p.y,0)-3.5;
				readklock(&curt);oldt = curt;
				updatevxl();
				updatelighting(0,0,0,VSID,VSID,MAXZDIM);
                mode = 2;
                return;
            }
            startdirectdraw(&frameptr, &pitch, &xdim, &ydim);
            voxsetframebuffer(frameptr, pitch, xdim, ydim);

            clearscreen(0);
            print6x8(0,0,0xffffffff, -1, "loading map: %lu%/%lu", (unsigned long int)network.currs, (unsigned long int)network.msize);

            stopdirectdraw();
            nextpage();

            readkeyboard();
            if(keystatus[ctr_quit]){
                MessageBox(ghwnd, "Aborted map loading", "", MB_OK);
                quitloop();
            }

            return;
        }
        case 2:{ //Main Game Loop

			oldt = curt;readklock(&curt);fsynctics = curt-oldt;
			updatetime(fsynctics, curt);
		
            startdirectdraw(&frameptr,&pitch,&xdim,&ydim);
            voxsetframebuffer(frameptr,pitch,xdim,ydim);

            setcamera(&ispr.e,&ispr.rs,&ispr.rh,&ispr.rf,xres*.5,yres*.5,xres*.5);
            opticast();
			updatevxl();

			//print6x8(0,0,0xffffffff, -1, "pos: x %f, y %f, z %f",ispr.e.x, ispr.e.y, ispr.e.z);
            //print6x8(0,9,0xffffffff, -1, "rot: x %f, y %f, z %f",ispr.rf.x, ispr.rf.y, ispr.rf.z);

            stopdirectdraw();
            nextpage();
			
            readkeyboard();
			
			if (keystatus[controls[ctr_quit]]) quitloop();
			if(keystatus[controls[ctr_save_vxl]])savevxl("aos-test.vxl");
			
			//set key states
			if(keystatus[controls[ctr_forward]])ispr.movf=1;else ispr.movf=0;
			if(keystatus[controls[ctr_back]])ispr.movb=1;else ispr.movb=0;
			if(keystatus[controls[ctr_left]])ispr.movl=1;else ispr.movl=0;
			if(keystatus[controls[ctr_right]])ispr.movr=1;else ispr.movr=0;
			if((ispr.vel.z>=0 && ispr.vel.z<0.017) && !ispr.airborne && keystatus[controls[ctr_jump]]){
            ispr.movj=1;keystatus[controls[ctr_jump]]=0;}else keystatus[controls[ctr_jump]]=0;
            if(keystatus[controls[ctr_crouch]]){if(!ispr.movc)crouch(&ispr);}else if(ispr.movc)uncrouch(&ispr);
            if(keystatus[controls[ctr_sneak]])ispr.movsn=1;else ispr.movsn=0;
            if(keystatus[controls[ctr_sprint]] && !ispr.movc && !ispr.movsn)ispr.movsp=1;else ispr.movsp=0;
			
			move_player(&ispr);
			
            //rotate view
			readmouse(&mousex,&mousey,&mouseb);
			mousex *= 0.008;mousey *= 0.008;
			rotx += mousex, roty += mousey;
            if(rotx>RADIUS)rotx-=RADIUS;else if(rotx<-RADIUS)rotx+=RADIUS;
			if(roty>PI2)roty=PI2;else if(roty<-PI2)roty=-PI2;
			rotate_player(&ispr,rotx,roty);
			
            return;
        }
    }
}

void uninitapp (){

    network.~CNet();
    free(vxlmap);

    uninitvoxlap();
}

#if 0
!endif
#endif // 0
