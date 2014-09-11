#if 0 //To compile, first compile game.c to generate the OBJ files, then type: "nmake simple.c"
simple.exe : simple.obj voxlap5.obj v5.obj kplib.obj winmain.obj
	link simple voxlap5 v5 kplib winmain ddraw.lib dinput.lib ole32.lib dxguid.lib user32.lib gdi32.lib ws2_32.lib winmm.lib enet.lib /opt:nowin98
simple.obj : simple.c voxlap5.h sysmain.h
	cl /c /J /TP simple.c /Ox /Ob2 /G6Fy /Gs /ML /QIfist
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

#include <enet/enet.h>
#include <zlib.h>

#pragma comment(lib, "libz.dll.a")

dpoint3d ipos, istr, ihei, ifor;

static ENetHost *client;
static ENetAddress host_address;


long initapp (long argc, char **argv)
{
   xres = 640; yres = 480; colbits = 32; fullscreen = 0;
   initvoxlap();
   loadnul(&ipos, &istr, &ihei, &ifor);

   return(0);
}

void doframe ()
{
   long frameptr, pitch, xdim, ydim;
   static long pic[256*192];
	static float ang = 0;
	clearscreen(0);
	startdirectdraw(&frameptr,&pitch,&xdim,&ydim);
	voxsetframebuffer((long)pic,256*4,256,192);
	setcamera(&ipos,&istr,&ihei,&ifor,256*.5,192*.5,256*.5);
	opticast();
	float rx = 256*.5;
	float ry = 192*.5 - 192*cos(ang);
	float rz = 256*.5 + 192*sin(ang);
	drawpicinquad((long)pic,256*4,256,192,frameptr,pitch,xdim,ydim,
		xdim*.5-rx*xdim*.5/rz,ydim*.5+ry*xdim*.5/rz,
		xdim*.5+rx*xdim*.5/rz,ydim*.5+ry*xdim*.5/rz,xdim,ydim,0,ydim);
	//ang -= .02; if (ang < -0.75) ang = 0;
	ang += .02; if (ang >= 2.35) ang = -.75;

   stopdirectdraw();
   nextpage();
   readkeyboard(); if (keystatus[1]) quitloop();

}

void uninitapp () { /*uninitvoxlap();*/ kzuninit(); uninitvoxlap();}

#if 0
!endif
#endif // 0
