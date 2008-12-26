/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_BUFFERSOURCE_
#define _H_COM_DIAG_CONCHA_BUFFERSOURCE_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"
#include <sys/types.h>

typedef struct BufferSource {
	Source source;
	char * buffer;
	char * next;
	char * past;
} BufferSource;

extern Source * openBufferSource(BufferSource * that, char * pointer, size_t bytes);
extern int readBufferSource(Source * that);
extern int pushBufferSource(Source * that, char data);
extern int closeBufferSource(Source * that);

#endif
