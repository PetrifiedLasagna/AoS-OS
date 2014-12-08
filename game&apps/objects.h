#ifndef OBJECTS_H
#define OBJECTS_H
#include "voxlap5.h"

/* Physics borrowed from Pysnip/Pyspades */
enum{
    spectator=-1,blue,green
};
enum plrtool{
	spade, block, gun, grenade
};
enum plrweap{
	rifle, smg, shotgun
};
struct plrsprite{
	vx5sprite sprdata;
	dpoint3d p,e,rf,rs,rh;
	point3d vel,ra;
	int health;
	unsigned long score;
	char name[16];
	
	plrtool tool;
	plrweap weapon;
    int myteam;
    
	float lastclimb;
	
	bool movf:1,movb:1,movl:1,movr:1,
	movj:1,movc:1,movsn:1,movsp:1,
	reload:1,primaryf:1,secondaryf:1,
	airborne:1,wade:1;
};

void uncrouch(plrsprite*);
void crouch(plrsprite*);
long move_player(plrsprite*);
void boxclipmove(plrsprite*);
int clipbox(double,double,double);
void reposition_player(plrsprite*,dpoint3d*);
void rotate_player(plrsprite*,float,float);
void updatetime(float,float);
void initializeplayer(plrsprite*);

#endif