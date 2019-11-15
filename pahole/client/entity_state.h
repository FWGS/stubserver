typedef struct {
    /* typedef byte */ unsigned char r;                              /*   428     1 */
    /* typedef byte */ unsigned char g;                              /*   429     1 */
    /* typedef byte */ unsigned char b;                              /*   430     1 */
} color24;
typedef struct entity_state_s {
	int                        entityType;           /*     0     4 */
	int                        number;               /*     4     4 */
	float                      msg_time;             /*     8     4 */
	int                        messagenum;           /*    12     4 */
	vec3_t                     origin;               /*    16    12 */
	vec3_t                     angles;               /*    28    12 */
	int                        modelindex;           /*    40     4 */
	int                        sequence;             /*    44     4 */
	float                      frame;                /*    48     4 */
	int                        colormap;             /*    52     4 */
	short int                  skin;                 /*    56     2 */
	short int                  solid;                /*    58     2 */
	int                        effects;              /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	float                      scale;                /*    64     4 */
	byte                       eflags;               /*    68     1 */

	/* XXX 3 bytes hole, try to pack */

	int                        rendermode;           /*    72     4 */
	int                        renderamt;            /*    76     4 */
	color24                    rendercolor;          /*    80     3 */

	/* XXX 1 byte hole, try to pack */

	int                        renderfx;             /*    84     4 */
	int                        movetype;             /*    88     4 */
	float                      animtime;             /*    92     4 */
	float                      framerate;            /*    96     4 */
	int                        body;                 /*   100     4 */
	byte                       controller[4];        /*   104     4 */
	byte                       blending[4];          /*   108     4 */
	vec3_t                     velocity;             /*   112    12 */
	vec3_t                     mins;                 /*   124    12 */
	/* --- cacheline 2 boundary (128 bytes) was 8 bytes ago --- */
	vec3_t                     maxs;                 /*   136    12 */
	int                        aiment;               /*   148     4 */
	int                        owner;                /*   152     4 */
	float                      friction;             /*   156     4 */
	float                      gravity;              /*   160     4 */
	int                        team;                 /*   164     4 */
	int                        playerclass;          /*   168     4 */
	int                        health;               /*   172     4 */
	qboolean                   spectator;            /*   176     4 */
	int                        weaponmodel;          /*   180     4 */
	int                        gaitsequence;         /*   184     4 */
	vec3_t                     basevelocity;         /*   188    12 */
	/* --- cacheline 3 boundary (192 bytes) was 8 bytes ago --- */
	int                        usehull;              /*   200     4 */
	int                        oldbuttons;           /*   204     4 */
	int                        onground;             /*   208     4 */
	int                        iStepLeft;            /*   212     4 */
	float                      flFallVelocity;       /*   216     4 */
	float                      fov;                  /*   220     4 */
	int                        weaponanim;           /*   224     4 */
	vec3_t                     startpos;             /*   228    12 */
	vec3_t                     endpos;               /*   240    12 */
	float                      impacttime;           /*   252     4 */
	/* --- cacheline 4 boundary (256 bytes) --- */
	float                      starttime;            /*   256     4 */
	int                        iuser1;               /*   260     4 */
	int                        iuser2;               /*   264     4 */
	int                        iuser3;               /*   268     4 */
	int                        iuser4;               /*   272     4 */
	float                      fuser1;               /*   276     4 */
	float                      fuser2;               /*   280     4 */
	float                      fuser3;               /*   284     4 */
	float                      fuser4;               /*   288     4 */
	vec3_t                     vuser1;               /*   292    12 */
	vec3_t                     vuser2;               /*   304    12 */
	vec3_t                     vuser3;               /*   316    12 */
	/* --- cacheline 5 boundary (320 bytes) was 8 bytes ago --- */
	vec3_t                     vuser4;               /*   328    12 */

	/* size: 340, cachelines: 6, members: 62 */
	/* sum members: 336, holes: 2, sum holes: 4 */
	/* last cacheline: 20 bytes */
} entity_state_t;
