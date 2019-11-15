
#define FL_FLY		(1<<0)
#define FL_SWIM		(1<<1)
#define FL_CONVEYOR		(1<<2)
#define FL_CLIENT		(1<<3)
#define FL_INWATER		(1<<4)
#define FL_MONSTER		(1<<5)
#define FL_GODMODE		(1<<6)
#define FL_NOTARGET		(1<<7)
#define FL_SKIPLOCALHOST	(1<<8)
#define FL_ONGROUND		(1<<9)
#define FL_PARTIALGROUND	(1<<10)
#define FL_WATERJUMP	(1<<11)
#define FL_FROZEN		(1<<12)
#define FL_FAKECLIENT	(1<<13)
#define FL_DUCKING		(1<<14)
#define FL_FLOAT		(1<<15)
#define FL_GRAPHED		(1<<16)

#define DAMAGE_NO			0
#define DAMAGE_YES			1
#define DAMAGE_AIM			2


#define MOVETYPE_NONE		0
// unused
//#define	MOVETYPE_ANGLENOCLIP	1
//#define	MOVETYPE_ANGLECLIP		2
#define MOVETYPE_WALK		3
#define MOVETYPE_STEP		4
#define MOVETYPE_FLY		5
#define MOVETYPE_TOSS		6
#define MOVETYPE_PUSH		7
#define MOVETYPE_NOCLIP		8
#define MOVETYPE_FLYMISSILE		9
#define MOVETYPE_BOUNCE		10
#define MOVETYPE_BOUNCEMISSILE	11
#define MOVETYPE_FOLLOW		12
#define MOVETYPE_PUSHSTEP		13
// xash3d extension
#define MOVETYPE_COMPOUND		14

#define SOLID_NOT			0
#define SOLID_TRIGGER		1
#define SOLID_BBOX			2
#define SOLID_SLIDEBOX		3
#define SOLID_BSP			4
// xash3d extension
#define SOLID_CUSTOM		5
