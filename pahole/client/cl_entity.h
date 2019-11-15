
//#include "entity_state.h"

typedef struct latchedvars_s {
               float              prevanimtime;                                         /*  2832     4 */
               float              sequencetime;                                         /*  2836     4 */
               /* typedef byte */ unsigned char      prevseqblending[2];                /*  2840     2 */

               /* XXX 2 bytes hole, try to pack */

               /* typedef vec3_t */ /* typedef vec_t */ float              prevorigin[3]; /*  2844    12 */
               /* typedef vec3_t */ /* typedef vec_t */ float              prevangles[3]; /*  2856    12 */
               int                prevsequence;                                         /*  2868     4 */
               float              prevframe;                                            /*  2872     4 */
               /* typedef byte */ unsigned char      prevcontroller[4];                 /*  2876     4 */
               /* --- cacheline 45 boundary (2880 bytes) --- */
               /* typedef byte */ unsigned char      prevblending[2];                   /*  2880     2 */
       } latchedvars_t; /*  2832    52 */

typedef struct mouth_s {
        /* typedef byte */ unsigned char      mouthopen;                         /*  2824     1 */
        /* typedef byte */ unsigned char      sndcount;                          /*  2825     1 */

        /* XXX 2 bytes hole, try to pack */

        int                sndavg;                                               /*  2828     4 */
} mouth_t;

typedef struct
{
    unsigned int       r;                                                    /*  2984     4 */
    unsigned int       g;                                                    /*  2988     4 */
    unsigned int       b;                                                    /*  2992     4 */
    unsigned int       a;
} colorVec;

typedef struct {
    float              animtime;                                             /*  1032     4 */
    /* typedef vec3_t */ /* typedef vec_t */ float              origin[3];   /*  1036    12 */
    /* typedef vec3_t */ /* typedef vec_t */ float              angles[3];   /*  1048    12 */
} position_history_t;

struct cl_entity_s {
	int                        index;                /*     0     4 */
	qboolean                   player;               /*     4     4 */
	entity_state_t             baseline;             /*     8   340 */
	/* --- cacheline 5 boundary (320 bytes) was 28 bytes ago --- */
	entity_state_t             prevstate;            /*   348   340 */
	/* --- cacheline 10 boundary (640 bytes) was 48 bytes ago --- */
	entity_state_t             curstate;             /*   688   340 */
	/* --- cacheline 16 boundary (1024 bytes) was 4 bytes ago --- */
	int                        current_position;     /*  1028     4 */
	position_history_t         ph[64];               /*  1032  1792 */
	/* --- cacheline 44 boundary (2816 bytes) was 8 bytes ago --- */
	mouth_t                    mouth;                /*  2824     8 */
	latchedvars_t              latched;              /*  2832    52 */
	/* --- cacheline 45 boundary (2880 bytes) was 4 bytes ago --- */
	float                      lastmove;             /*  2884     4 */
	vec3_t                     origin;               /*  2888    12 */
	vec3_t                     angles;               /*  2900    12 */
	vec_t                      attachment[4][3];     /*  2912    48 */
	/* --- cacheline 46 boundary (2944 bytes) was 16 bytes ago --- */
	int                        trivial_accept;       /*  2960     4 */
	struct model_s *           model;                /*  2964     4 */
	struct efrag_s *           efrag;                /*  2968     4 */
	struct mnode_s *           topnode;              /*  2972     4 */
	float                      syncbase;             /*  2976     4 */
	int                        visframe;             /*  2980     4 */
	colorVec                   cvFloorColor;         /*  2984    16 */

	/* size: 3000, cachelines: 47, members: 20 */
	/* last cacheline: 56 bytes */
};
