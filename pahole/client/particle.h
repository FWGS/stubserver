struct particle_s {
    vec3_t              org;                  /*     0    12 */
	short int                  color;                /*    12     2 */
	short int                  packedColor;          /*    14     2 */
	struct particle_s *         next;                 /*    16     4 */
    vec3_t              vel;                  /*    20    12 */
	float                      ramp;                 /*    32     4 */
	float                      die;                  /*    36     4 */
	ptype_t                    type;                 /*    40     4 */
	void                       (*deathfunc)(struct particle_s *); /*    44     4 */
	void                       (*callback)(struct particle_s *, float); /*    48     4 */
	unsigned char              context;              /*    52     1 */

	/* size: 56, cachelines: 1, members: 11 */
	/* padding: 3 */
	/* last cacheline: 56 bytes */
};
