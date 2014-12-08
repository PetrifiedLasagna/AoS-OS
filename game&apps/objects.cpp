#include <math.h>
#include "objects.h"

/* >>Physics<< borrowed from pyspades/pysnip */
#define SQRT 0.70710678f
#define FALL_SLOW_DOWN 0.24f
#define FALL_DAMAGE_VELOCITY 0.58
#define FALL_DAMAGE_SCALAR 4096

static float fsynctics, totalt;

void uncrouch(plrsprite *p){
    float px = p->p.x, py = p->p.y, pz = p->p.z;
    if(p->airborne){
        if(!clipbox(px,py,pz+0.9)){
            p->movc = 0;
        }else{
            p->p.z-=.9-(floorf(pz+1)-pz);
            p->movc = 0;
        }
    }else{
        if(!clipbox(px,py,pz-0.9f)){
            p->p.z-=.9;
            p->movc = 0;
        }
    }
}

void crouch(plrsprite *p){
    p->movc = 1;
    if(!p->airborne)p->p.z+=.9;
}

long move_player(plrsprite *p){

	float f, f2;
	
	if(p->movj){
		p->movj=0;
		p->vel.z = -0.36;
	}
	
	f = fsynctics;
	if(p->airborne)f *= 0.1f;
	else if(p->movc)f *= 0.3f;
	else if((p->secondaryf && p->tool==gun) || p->movsn)
			f *= 0.5f;
	else if(p->movsp)f *= 1.3f;
	
	if((p->movf||p->movb)&&(p->movl||p->movr))
		f *= SQRT;
	
	if(p->movf){
		p->vel.x += p->rf.x*f;
		p->vel.y += p->rf.y*f;
	}else if(p->movb){
		p->vel.x -= p->rf.x*f;
		p->vel.y -= p->rf.y*f;
	}
	if(p->movl){
		p->vel.x -= p->rs.x*f;
		p->vel.y -= p->rs.y*f;
	}else if(p->movr){
		p->vel.x += p->rs.x*f;
		p->vel.y += p->rs.y*f;
	}
	
	f = fsynctics + 1;
	p->vel.z += fsynctics;
	p->vel.z /= f;
	if(p->wade)f = fsynctics*6.f + 1;
	else if(!(p->airborne))f = fsynctics*4.f + 1;
	
	p->vel.x /= f;p->vel.y /= f;
	f2 = p->vel.z;
	boxclipmove(p);
	
	if(!p->vel.z && (f2 > FALL_SLOW_DOWN)){
		p->vel.x *= 0.5f;
		p->vel.y *= 0.5f;
		if(f2 > FALL_DAMAGE_VELOCITY){
			f2 -= FALL_DAMAGE_VELOCITY;
			return (long)(f2*f2*FALL_DAMAGE_SCALAR);
		}
		return -1;
	}
	return 0;
}

void boxclipmove(plrsprite *p){
	float offset, m, f, nx, ny, nz, z;
	long climb = 0;
	
	f = fsynctics*32.f;
	nx = f*p->vel.x+p->p.x;
	ny = f*p->vel.y+p->p.y;
	
	if(p->movc){
		offset = 0.45f;
		m = 0.9f;
	}else{
		offset = 0.9f;
		m = 1.35f;
	}
	
	nz = p->p.z+offset;
	
	if(p->vel.x<0)f = -0.45f;
	else f = 0.45f;
	z=m;
	while(z>=-1.36f && !clipbox(nx+f, p->p.y-0.45f, nz+z) && !clipbox(nx+f, p->p.y+0.45f, nz+z))
		z-=0.9f;
	if(z<-1.36f)p->p.x = nx;
	else if(!p->movc && p->rf.z<0.5f && !p->movsp){
		z=0.35f;
		while(z>=-2.36f && !clipbox(nx+f, p->p.y-0.45f, nz+z) && !clipbox(nx+f, p->p.y+0.45f, nz+z))
			z-=0.9f;
		if(z<-2.36f){
			p->p.x = nx;
			climb=1;
		}else p->vel.x = 0;
	}else p->vel.x = 0;
	
	if(p->vel.y < 0)f=-0.45f;
	else f=0.45f;
	z=m;
	while(z>=-1.36f && !clipbox(p->p.x-0.45f, ny+f, nz+z) && !clipbox(p->p.x+0.45f, ny+f, nz+z))
		z-=0.9f;
	if(z<-1.36f)p->p.y = ny;
	else if(!p->movc && p->rf.z<0.5f && !p->movsp && !climb){
		z=0.35f;
		while(z>=-2.36f && !clipbox(p->p.x-0.45f, ny+f, nz+z) && !clipbox(p->p.x+0.45f, ny+f, nz+z))
			z-=0.9f;
		if(z<-2.36f){
			p->p.y = ny;
			climb=1;
		}else p->vel.y = 0;
	}else if(!climb)p->vel.y = 0;
	
	if(climb){
		p->vel.x *= 0.5f;
		p->vel.y *= 0.5f;
		p->lastclimb = totalt;
		nz--;
		m=-1.35f;
	}else{
		if(p->vel.z<0)m=-m;
		nz += p->vel.z*fsynctics*32.f;
	}
	
	p->airborne=1;
	
	if(clipbox(p->p.x-0.45f, p->p.y-0.45f, nz+m) ||
		clipbox(p->p.x-0.45f, p->p.y+0.45f, nz+m) ||
		clipbox(p->p.x+0.45f, p->p.y-0.45f, nz+m) ||
		clipbox(p->p.x+0.45f, p->p.y+0.45f, nz+m)){
		if(p->vel.z>=0){
			p->wade = p->p.z > 61;
			p->airborne=0;
		}
		p->vel.z=0;
	}else p->p.z = nz-offset;
	
	reposition_player(p, &p->p);
}

//same as isvoxelsolid but water is empty && out of bounds returns true
int clipbox(double x, double y, double z){
    x = floor(x);y = floor(y);
	int sz;

    if (x < 0 || x >= 512 || y < 0 || y >= 512)
        return 1;
    else if (z < 0)
        return 0;
    sz = floor(z);
    if(sz == 63)
        sz=62;
    else if (sz >= 64)
        return 1;
    return isvoxelsolid((long)x,(long)y,(long)sz);
}

void reposition_player(plrsprite *p, dpoint3d *newp){
	float f;
	
	p->sprdata.p.x = p->e.x = newp->x;
	p->sprdata.p.x = p->e.y = newp->y;
	p->sprdata.p.x = p->e.z = newp->z;
	f = p->lastclimb-totalt;
	if(f>-0.25f)p->e.z += (f+0.25)/0.25;
}

void rotate_player(plrsprite *p, float mx, float my){
    if(p->myteam!=spectator){
        p->rf.x = 1;p->rf.y = 0;p->rf.z = 0;
        p->rs.x = 0;p->rs.y = 1;p->rs.z = 0;
        p->rh.x = 0;p->rh.y = 0;p->rh.z = 1;
        dorthorotate(0,my,mx,&p->rs,&p->rh,&p->rf);
    }
	return;
}

void updatetime(float tics, float total){
	fsynctics = tics;
	totalt = total;
}

void initializeplayer(plrsprite *p){
	p->sprdata.p.x = p->e.x = p->p.x = p->vel.x = 0;
	p->sprdata.p.y = p->e.y = p->p.y = p->vel.y = 0;
	p->sprdata.p.z = p->e.z = p->p.z = p->vel.z = 0;
	
	p->rs.x = 0; p->rs.y = 1; p->rs.z = 0;
	p->rh.x = 0; p->rh.y = 0; p->rh.z = 1;
	p->rf.x = 1; p->rf.y = 0; p->rf.z = 0;
	
	p->movf = p->movb = p->movl = p->movr = p->movj =
		p->movc = p->movsn = p->movsp =
		p->reload = p->primaryf = p->secondaryf = 0;
	
	p->airborne = p->wade = 0;
	p->lastclimb = 0;
    p->myteam = -2;
}
