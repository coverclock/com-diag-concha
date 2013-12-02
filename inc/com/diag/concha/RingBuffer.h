/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_RINGBUFFER_
#define _H_COM_DIAG_CONCHA_RINGBUFFER_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/Source.h"
#include "com/diag/concha/Sink.h"
#include <sys/types.h>

typedef struct RingBuffer {

    /**
     * Source interface.
     */
	Source source;

    /**
     * Sink interface.
     */
    Sink sink;

    /**
     * Pointer to first octet in buffer.
     */
	char * buffer;

    /**
     * Size of the buffer in octets.
     */
    size_t size;

    /**
     * Running number of reads (wraps okay).
     */
    size_t reads;

    /**
     * Running number of writes (wraps okay).
     */
    size_t writes;

} RingBuffer;

/**
 * Open a Ring Buffer.
 * @param that points to the Ring Buffer.
 * @param buffer points to the buffer.
 * @param size is the capacity of the buffer in octets.
 * @return a pointer to the Ring Buffer.
 */
extern RingBuffer * openRingBuffer(RingBuffer * that, void * buffer, size_t size);

/**
 * Return a pointer to the Source interface of a Ring Buffer.
 * @param that points to the Ring Buffer.
 * @return a pointer to the Source interface of the Ring Buffer.
 */
extern Source * sourceRingBuffer(RingBuffer * that);

/**
 * Return a pointer to the Sink interface of a Ring Buffer.
 * @param that points to the Ring Buffer.
 * @return a pointer to the Source interface of the Ring Buffer.
 */
extern Sink * sinkRingBuffer(RingBuffer * that);

#endif
