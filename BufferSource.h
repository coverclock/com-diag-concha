/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_BUFFERSOURCE_
#define _H_COM_DIAG_CONCHA_BUFFERSOURCE_

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"
#include <sys/types.h>

typedef struct BufferSource {

    /**
     * Base class.
     */
	Source source;

    /**
     * Pointer to beginning of buffer.
     */
	char * buffer;

    /**
     * Pointer to next octet to be read from buffer.
     */
	char * next;

    /**
     * Pointer to octet past end of buffer.
     */
	char * past;

} BufferSource;

/**
 * Open a Buffer Source. The Source will produce octets until it is empty.
 * @param that points to the Buffer Sink.
 * @param buffer points to the buffer.
 * @param size is the capacity of the buffer in octets.
 * @return a pointer to the Buffer Sink as a Sink.
 */
extern Source * openBufferSource(BufferSource * that, void * buffer, size_t size);

#endif
