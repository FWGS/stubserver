struct efx_api_s {
	particle_t *               (*R_AllocParticle)(void (*)(struct particle_s *, float)); /*     0     4 */
	void                       (*R_BlobExplosion)(float *);                          /*     4     4 */
	void                       (*R_Blood)(float *, float *, int, int);               /*     8     4 */
	void                       (*R_BloodSprite)(float *, int, int, int, float);      /*    12     4 */
	void                       (*R_BloodStream)(float *, float *, int, int);         /*    16     4 */
	void                       (*R_BreakModel)(float *, float *, float *, float, float, int, int, char); /*    20     4 */
	void                       (*R_Bubbles)(float *, float *, float, int, int, float); /*    24     4 */
	void                       (*R_BubbleTrail)(float *, float *, float, int, int, float); /*    28     4 */
	void                       (*R_BulletImpactParticles)(float *);                  /*    32     4 */
	void                       (*R_EntityParticles)(struct cl_entity_s *);            /*    36     4 */
	void                       (*R_Explosion)(float *, int, float, float, int);      /*    40     4 */
	void                       (*R_FizzEffect)(struct cl_entity_s *, int, int);       /*    44     4 */
	void                       (*R_FireField)(float *, int, int, int, int, float);   /*    48     4 */
	void                       (*R_FlickerParticles)(float *);                       /*    52     4 */
	void                       (*R_FunnelSprite)(float *, int, int);                 /*    56     4 */
	void                       (*R_Implosion)(float *, float, int, float);           /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	void                       (*R_LargeFunnel)(float *, int);                       /*    64     4 */
	void                       (*R_LavaSplash)(float *);                             /*    68     4 */
	void                       (*R_MultiGunshot)(float *, float *, float *, int, int, int *); /*    72     4 */
	void                       (*R_MuzzleFlash)(float *, int);                       /*    76     4 */
	void                       (*R_ParticleBox)(float *, float *, unsigned char, unsigned char, unsigned char, float); /*    80     4 */
	void                       (*R_ParticleBurst)(float *, int, int, float);         /*    84     4 */
	void                       (*R_ParticleExplosion)(float *);                      /*    88     4 */
	void                       (*R_ParticleExplosion2)(float *, int, int);           /*    92     4 */
	void                       (*R_ParticleLine)(float *, float *, unsigned char, unsigned char, unsigned char, float); /*    96     4 */
	void                       (*R_PlayerSprites)(int, int, int, int);               /*   100     4 */
	void                       (*R_Projectile)(float *, float *, int, int, int, void (*)(struct tempent_s *, struct pmtrace_s *)); /*   104     4 */
	void                       (*R_RicochetSound)(float *);                          /*   108     4 */
	void                       (*R_RicochetSprite)(float *, struct model_s *, float, float); /*   112     4 */
	void                       (*R_RocketFlare)(float *);                            /*   116     4 */
	void                       (*R_RocketTrail)(float *, float *, int);              /*   120     4 */
	void                       (*R_RunParticleEffect)(float *, float *, int, int);   /*   124     4 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	void                       (*R_ShowLine)(float *, float *);                      /*   128     4 */
	void                       (*R_SparkEffect)(float *, int, int, int);             /*   132     4 */
	void                       (*R_SparkShower)(float *);                            /*   136     4 */
	void                       (*R_SparkStreaks)(float *, int, int, int);            /*   140     4 */
	void                       (*R_Spray)(float *, float *, int, int, int, int, int); /*   144     4 */
	void                       (*R_Sprite_Explode)(TEMPENTITY *, float, int);        /*   148     4 */
	void                       (*R_Sprite_Smoke)(TEMPENTITY *, float);               /*   152     4 */
	void                       (*R_Sprite_Spray)(float *, float *, int, int, int, int); /*   156     4 */
	void                       (*R_Sprite_Trail)(int, float *, float *, int, int, float, float, float, int, float); /*   160     4 */
	void                       (*R_Sprite_WallPuff)(TEMPENTITY *, float);            /*   164     4 */
	void                       (*R_StreakSplash)(float *, float *, int, int, float, int, int); /*   168     4 */
	void                       (*R_TracerEffect)(float *, float *);                  /*   172     4 */
	void                       (*R_UserTracerParticle)(float *, float *, float, int, float, unsigned char, void (*)(struct particle_s *)); /*   176     4 */
	particle_t *               (*R_TracerParticles)(float *, float *, float);        /*   180     4 */
	void                       (*R_TeleportSplash)(float *);                         /*   184     4 */
	void                       (*R_TempSphereModel)(float *, float, float, int, int); /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	TEMPENTITY *               (*R_TempModel)(float *, float *, float *, float, int, int); /*   192     4 */
	TEMPENTITY *               (*R_DefaultSprite)(float *, int, float);              /*   196     4 */
	TEMPENTITY *               (*R_TempSprite)(float *, float *, float, int, int, int, float, float, int); /*   200     4 */
	int                        (*Draw_DecalIndex)(int);                              /*   204     4 */
	int                        (*Draw_DecalIndexFromName)(char *);                   /*   208     4 */
	void                       (*R_DecalShoot)(int, int, int, float *, int);         /*   212     4 */
	void                       (*R_AttachTentToPlayer)(int, int, float, float);      /*   216     4 */
	void                       (*R_KillAttachedTents)(int);                          /*   220     4 */
	BEAM *                     (*R_BeamCirclePoints)(int, float *, float *, int, float, float, float, float, float, int, float, float, float, float); /*   224     4 */
	BEAM *                     (*R_BeamEntPoint)(int, float *, int, float, float, float, float, float, int, float, float, float, float); /*   228     4 */
	BEAM *                     (*R_BeamEnts)(int, int, int, float, float, float, float, float, int, float, float, float, float); /*   232     4 */
	BEAM *                     (*R_BeamFollow)(int, int, float, float, float, float, float, float); /*   236     4 */
	void                       (*R_BeamKill)(int);                                   /*   240     4 */
	BEAM *                     (*R_BeamLightning)(float *, float *, int, float, float, float, float, float); /*   244     4 */
	BEAM *                     (*R_BeamPoints)(float *, float *, int, float, float, float, float, float, int, float, float, float, float); /*   248     4 */
	BEAM *                     (*R_BeamRing)(int, int, int, float, float, float, float, float, int, float, float, float, float); /*   252     4 */
	/* --- cacheline 4 boundary (256 bytes) --- */
	dlight_t *                 (*CL_AllocDlight)(int);                               /*   256     4 */
	dlight_t *                 (*CL_AllocElight)(int);                               /*   260     4 */
	TEMPENTITY *               (*CL_TempEntAlloc)(float *, struct model_s *);         /*   264     4 */
	TEMPENTITY *               (*CL_TempEntAllocNoModel)(float *);                   /*   268     4 */
	TEMPENTITY *               (*CL_TempEntAllocHigh)(float *, struct model_s *);     /*   272     4 */
	TEMPENTITY *               (*CL_TentEntAllocCustom)(float *, struct model_s *, int, void (*)(struct tempent_s *, float, float)); /*   276     4 */
	void                       (*R_GetPackedColor)(short int *, short int);          /*   280     4 */
	short int                  (*R_LookupColor)(unsigned char, unsigned char, unsigned char); /*   284     4 */
	void                       (*R_DecalRemoveAll)(int);                             /*   288     4 */
	void                       (*R_FireCustomDecal)(int, int, int, float *, int, float); /*   292     4 */

	/* size: 296, cachelines: 5, members: 74 */
	/* last cacheline: 40 bytes */
};
