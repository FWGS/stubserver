struct mstudioevent_s {
	int                        frame;                /*     0     4 */
	int                        event;                /*     4     4 */
	int                        type;                 /*     8     4 */
	char                       options[64];          /*    12    64 */

	/* size: 76, cachelines: 2, members: 4 */
	/* last cacheline: 12 bytes */
};
