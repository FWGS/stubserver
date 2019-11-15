struct triangleapi_s {
	int                        version;                                              /*     0     4 */
	void                       (*RenderMode)(int);                                   /*     4     4 */
	void                       (*Begin)(int);                                        /*     8     4 */
	void                       (*End)(void);                                         /*    12     4 */
	void                       (*Color4f)(float, float, float, float);               /*    16     4 */
	void                       (*Color4ub)(unsigned char, unsigned char, unsigned char, unsigned char); /*    20     4 */
	void                       (*TexCoord2f)(float, float);                          /*    24     4 */
	void                       (*Vertex3fv)(float *);                                /*    28     4 */
	void                       (*Vertex3f)(float, float, float);                     /*    32     4 */
	void                       (*Brightness)(float);                                 /*    36     4 */
	void                       (*CullFace)(TRICULLSTYLE);                            /*    40     4 */
	int                        (*SpriteTexture)(struct model_s *, int);               /*    44     4 */
	int                        (*WorldToScreen)(float *, float *);                   /*    48     4 */
	void                       (*Fog)(float *, float, float, int);                   /*    52     4 */
	void                       (*ScreenToWorld)(float *, float *);                   /*    56     4 */
	void                       (*GetMatrix)(int, float *);                           /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	int                        (*BoxInPVS)(float *, float *);                        /*    64     4 */
	void                       (*LightAtPoint)(float *, float *);                    /*    68     4 */
	void                       (*Color4fRendermode)(float, float, float, float, int); /*    72     4 */
	void                       (*FogParams)(float, int);                             /*    76     4 */

	/* size: 80, cachelines: 2, members: 20 */
	/* last cacheline: 16 bytes */
};
