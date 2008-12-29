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

typedef struct BufferSource {
	Source source;
	char * buffer;
	char * next;
	char * past;
} BufferSource;

/**
 * Open a Buffer Source. The Source will produce octets until it is empty.
 * @param that points to the Buffer Sink.
 * @param buffer points to the buffer.
 * @param size is the capacity of the buffer in octets.
 * @return a pointer to the Buffer Sink as a Sink.
 */
extern Source * openBufferSource(BufferSource * that, char * buffer, size_t size);

/**
 * Read an octet of data from the Source.
 * @param that points to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int readBufferSource(Source * that);

/**
 * Push an octet of data back into the Source. It will be the next octet
 * read from the Source. Only one octet can be pushed back before being
 * re-read from the Source. The octet is not literally pushed back into
 * the underlying storage medium.
 * @param that points to the Source.
 * @param data is an octet to push back to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int pushBufferSource(Source * that, char data);

/**
 * Close the Source. This has no effect on the Buffer Source.
 * @param that points to the Source.
 * @return 0 for success, <0 otherwise.
 */
extern int closeBufferSource(Source * that);

#endif
