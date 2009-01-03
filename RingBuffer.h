/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_RINGBUFFER_
#define _H_COM_DIAG_CONCHA_RINGBUFFER_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"
#include "Sink.h"
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

/**
 * Read an octet of data from the Source. If the Source is empty, EOD is
 * returned to indicate that no data is currently available but may be in
 * the future.
 * @param that points to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int readRingBuffer(Source * that);

/**
 * Push an octet of data back into the Source. Since the Ring Buffer may
 * consume as well produce data, this function may return EOD indicating
 * that there is temporarily no space in the Ring Buffer.
 * @param that points to the Source.
 * @param data is an octet to push back to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int pushRingBuffer(Source * that, char data);

/**
 * Write an octet of data to the Sink.
 * @param that points to the Sink.
 * @param data is an octet to write into the Sink.
 * @return data as an integer for success, <0 otherwise.
 */
extern int writeRingBuffer(Sink * that, char data);

/**
 * Close the Source. Closes the Ring Buffer Source. Has no effect on
 * the Ring Buffer.
 * @param that points to the Source.
 * @return 0 for success, <0 otherwise.
 */
extern int closeRingBufferSource(Source * that);

/**
 * Close the Sink. Closes the Ring Buffer Sink. Has no effect on
 * the Ring Buffer.
 * @param that points to the Sink.
 * @return 0 for success, <0 otherwise.
 */
extern int closeRingBufferSink(Sink * that);

#endif
