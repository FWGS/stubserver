typedef struct cmdalias_s {
	struct cmdalias_s *         next;                                                 /*     0     4 */
	char                       name[32];                                             /*     4    32 */
	char *                     value;                                                /*    36     4 */

	/* size: 40, cachelines: 1, members: 3 */
	/* last cacheline: 40 bytes */
} cmdalias_t;
