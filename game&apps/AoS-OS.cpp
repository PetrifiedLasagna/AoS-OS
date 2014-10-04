#if 0
AoS-OS.exe : AoS-OS.obj voxlap5.obj v5.obj kplib.obj winmain.obj AoS-OS.cpp cnet.obj cnet.cpp;
	link AoS-OS cnet voxlap5 v5 kplib winmain ddraw.lib dinput.lib ole32.lib dxguid.lib user32.lib gdi32.lib ws2_32.lib winmm.lib enet.lib zdll.lib /opt:nowin98
AoS-OS.obj : AoS-OS.cpp voxlap5.h sysmain.h;
	cl /c /J /TP AoS-OS.cpp /Ox /Ob2 /G6Fy /Gs /ML /QIfist
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
    BYTE *packet;

    int ret = network.check_packet(&packet);

    if(ret==0){
        switch(packet[0]){
        case DtaMapStart:
            network.handle_packet(packet);
            break;
        case DtaMapChunk:
            network.handle_packet(packet,sptr);
            break;
        }
    }else if(ret>1){
        return 1;
    }
    return 0;
}

long initapp (long argc, char **argv)
{

    xres = 800; yres = 600; colbits = 32; fullscreen = 0;
    if(initvoxlap())return -1;

    readklock(&currt);lastt = currt;

    vx5.fallcheck = 1;
	vx5.mipscandist = 69;
	vx5.maxscandist = 128;

    vxlmap = (long*) malloc(VSID*VSID*sizeof(long));
    if(network.init())return -2;

    if(argc>1){
        strcpy(address, argv[1]);
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
            if(network.connect_host(address, 3)){
                quitloop();
                return;
            }
            mode = 1;
            return;
        }
        case 1:{
            if(currt-lastt>=TIME_CHECK){
                lastt = currt;
                if(netframe()){
                    quitloop();
                    return;
                }
                if(network.netstatus==StatusConnected){
                    updatevxl();
                    network.disconnect_host(0);
                    mode = 2;
                }
            }
            return;
        }
        case 2:{

            startdirectdraw(&frameptr,&pitch,&xdim,&ydim);
            voxsetframebuffer(frameptr,pitch,xdim,ydim);

            setcamera(&ipos,&istr,&ihei,&ifor,xres*.5,yres*.5,xres*.5);
            opticast();

            stopdirectdraw();
            nextpage();
            readkeyboard(); if (keystatus[1]) quitloop();
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
