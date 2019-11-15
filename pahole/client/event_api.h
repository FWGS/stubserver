struct event_api_s {
	int                        version;                                              /*     0     4 */
	void                       (*EV_PlaySound)(int, float *, int, const char  *, float, float, int, int); /*     4     4 */
	void                       (*EV_StopSound)(int, int, const char  *);             /*     8     4 */
	int                        (*EV_FindModelIndex)(const char  *);                  /*    12     4 */
	int                        (*EV_IsLocal)(int);                                   /*    16     4 */
	int                        (*EV_LocalPlayerDucking)(void);                       /*    20     4 */
	void                       (*EV_LocalPlayerViewheight)(float *);                 /*    24     4 */
	void                       (*EV_LocalPlayerBounds)(int, float *, float *);       /*    28     4 */
	int                        (*EV_IndexFromTrace)(struct pmtrace_s *);              /*    32     4 */
	struct physent_s *          (*EV_GetPhysent)(int);                                /*    36     4 */
	void                       (*EV_SetUpPlayerPrediction)(int, int);                /*    40     4 */
	void                       (*EV_PushPMStates)(void);                             /*    44     4 */
	void                       (*EV_PopPMStates)(void);                              /*    48     4 */
	void                       (*EV_SetSolidPlayers)(int);                           /*    52     4 */
	void                       (*EV_SetTraceHull)(int);                              /*    56     4 */
	void                       (*EV_PlayerTrace)(float *, float *, int, int, struct pmtrace_s *); /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	void                       (*EV_WeaponAnimation)(int, int);                      /*    64     4 */
	short unsigned int         (*EV_PrecacheEvent)(int, const char  *);              /*    68     4 */
	void                       (*EV_PlaybackEvent)(int, const struct edict_s  *, short unsigned int, float, float *, float *, float, float, int, int, int, int); /*    72     4 */
	const char  *              (*EV_TraceTexture)(int, float *, float *);            /*    76     4 */
	void                       (*EV_StopAllSounds)(int, int);                        /*    80     4 */
	void                       (*EV_KillEvents)(int, const char  *);                 /*    84     4 */

	/* size: 88, cachelines: 2, members: 22 */
	/* last cacheline: 24 bytes */
};
