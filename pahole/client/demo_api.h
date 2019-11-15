struct demo_api_s {
	int                        (*IsRecording)(void);                                 /*     0     4 */
	int                        (*IsPlayingback)(void);                               /*     4     4 */
	int                        (*IsTimeDemo)(void);                                  /*     8     4 */
	void                       (*WriteBuffer)(int, unsigned char *);                 /*    12     4 */

	/* size: 16, cachelines: 1, members: 4 */
	/* last cacheline: 16 bytes */
};
