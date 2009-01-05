/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_BUFFERSINK_
#define _H_COM_DIAG_CONCHA_BUFFERSINK_

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Sink.h"
#include <sys/types.h>

typedef struct BufferSink {

    /**
     * Base class.
     */
	Sink sink;

    /**
     * Pointer to beginning of buffer.
     */
	char * buffer;

    /**
     * Pointer to next octet to be written to buffer.
     */
	char * next;

    /**
     * Pointer to octet past end of buffer.
     */
	char * past;

} BufferSink;

/**
 * Open a Buffer Sink. The Sink will consume octets until it is full.
 * @param that points to the Buffer Sink.
 * @param buffer points to the buffer.
 * @param size is the capacity of the buffer in octets.
 * @return a pointer to the Buffer Sink as a Sink.
 */
extern Sink * openBufferSink(BufferSink * that, void * buffer, size_t size);

#endif
