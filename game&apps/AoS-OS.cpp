#if 0
AoS-OS.exe : AoS-OS.obj voxlap5.obj v5.obj kplib.obj winmain.obj AoS-OS.cpp cnet.obj cnet.cpp;
	link AoS-OS cnet voxlap5 v5 kplib winmain ddraw.lib dinput.lib ole32.lib dxguid.lib user32.lib gdi32.lib ws2_32.lib winmm.lib /opt:nowin98

AoS-OS.obj : AoS-OS.cpp voxlap5.h sysmain.h;
	cl /c /J /TP AoS-OS.cpp /Ox /Ob2 /G6Fy /Gs /ML /QIfist
voxlap5.obj: voxlap5.c voxlap5.h;     cl /c /J /TP voxlap5.c   /Ox /Ob2 /G6Fy /Gs /ML
cnet.obj : cnet.cpp cnet.h sysmain.h;
    cl /c /J /TP cnet.cpp /Ox /Ob2 /G6Fy /Gs /ML /QIfist
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

extern "C" char *sptr[VSID*VSID];

static long *vxlmap;
static CNet network;
static int mode = 0;

static double lastt,currt;

char address[28];

dpoint3d ipos,istr,ifor,ihei;

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

long initapp (long argc, char **argv)
{

    xres = 800; yres = 600; colbits = 32; fullscreen = 1;
    if(initvoxlap())return -1;

    readklock(&currt);lastt = currt;

    vx5.fallcheck = 1;
	vx5.mipscandist = 69;
	vx5.maxscandist = 128;
	loadsky("BLUE");
	
	

    vxlmap = (long*) malloc(VSID*VSID*sizeof(long));
    if(network.init())return -2;

    if(argc>1){
        memset(sptr, 0, sizeof(char)*VSID*VSID);
        strcpy(address, argv[1]);
        ipos.x = ipos.y = VSID>>2;ipos.z = -3;
        double f = 90.0*PI/180.0;
		istr.x = cos(f); istr.y = sin(f); istr.z = 0;
		ihei.x = 0; ihei.y = 0; ihei.z = 1;
		ifor.x = sin(f); ifor.y = -cos(f); ifor.z = 0;
        return 0;
    }
    MessageBox(ghwnd, "Supply me with an AoS address(server address, port, version)\nEx. aos://16777343:32887:0.75", "", MB_OK);

    return(-3);
}

void doframe ()
{
    readklock(&currt);
    long frameptr, pitch, xdim, ydim;

    switch(mode){
        case 0:{
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
        case 1:{
            if(netframe()){
                quitloop();
                return;
            }
            if(network.netstatus==StatusConnected){
                updatevxl();
                network.disconnect_host(0);
				ipos.x = ipos.y = VSID*.5;
				ipos.z = getfloorz(ipos.x, ipos.y, 0)-2;
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
            if(keystatus[1]){
                MessageBox(ghwnd, "Aborted map loading", "", MB_OK);
                quitloop();
            }

            return;
        }
        case 2:{

            startdirectdraw(&frameptr,&pitch,&xdim,&ydim);
            voxsetframebuffer(frameptr,pitch,xdim,ydim);

            setcamera(&ipos,&istr,&ihei,&ifor,xres*.5,yres*.5,xres*.5);
            opticast();
			
			dorthorotate(0,0,0.02,&istr,&ihei,&ifor);

            stopdirectdraw();
            nextpage();
            readkeyboard(); if (keystatus[1]) quitloop(); if(keystatus[2])savevxl("aos-test.vxl");
            return;
        }
    }

}

void uninitapp () {

    network.~CNet();
    free(vxlmap);

    uninitvoxlap();
}

#if 0
!endif
#endif // 0
