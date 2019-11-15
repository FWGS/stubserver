struct ref_params_s {
	float                      vieworg[3];                                           /*     0    12 */
	float                      viewangles[3];                                        /*    12    12 */
	float                      forward[3];                                           /*    24    12 */
	float                      right[3];                                             /*    36    12 */
	float                      up[3];                                                /*    48    12 */
	float                      frametime;                                            /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	float                      time;                                                 /*    64     4 */
	int                        intermission;                                         /*    68     4 */
	int                        paused;                                               /*    72     4 */
	int                        spectator;                                            /*    76     4 */
	int                        onground;                                             /*    80     4 */
	int                        waterlevel;                                           /*    84     4 */
	float                      simvel[3];                                            /*    88    12 */
	float                      simorg[3];                                            /*   100    12 */
	float                      viewheight[3];                                        /*   112    12 */
	float                      idealpitch;                                           /*   124     4 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	float                      cl_viewangles[3];                                     /*   128    12 */
	int                        health;                                               /*   140     4 */
	float                      crosshairangle[3];                                    /*   144    12 */
	float                      viewsize;                                             /*   156     4 */
	float                      punchangle[3];                                        /*   160    12 */
	int                        maxclients;                                           /*   172     4 */
	int                        viewentity;                                           /*   176     4 */
	int                        playernum;                                            /*   180     4 */
	int                        max_entities;                                         /*   184     4 */
	int                        demoplayback;                                         /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	int                        hardware;                                             /*   192     4 */
	int                        smoothing;                                            /*   196     4 */
	struct usercmd_s *          cmd;                                                  /*   200     4 */
	struct movevars_s *         movevars;                                             /*   204     4 */
	int                        viewport[4];                                          /*   208    16 */
	int                        nextView;                                             /*   224     4 */
	int                        onlyClientDraw;                                       /*   228     4 */

	/* size: 232, cachelines: 4, members: 33 */
	/* last cacheline: 40 bytes */
};
