/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_BUFFERSINK_
#define _H_COM_DIAG_CONCHA_BUFFERSINK_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Sink.h"
#include <sys/types.h>

typedef struct BufferSink BufferSink;

struct BufferSink {
	Sink sink;
	char * buffer;
	char * next;
	char * past;
};

extern Sink * openBufferSink(BufferSink * that, char * pointer, size_t bytes);
extern int writeBufferSink(Sink * that, char data);
extern int closeBufferSink(Sink * that);

#endif
