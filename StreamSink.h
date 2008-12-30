/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_STREAMSINK_
#define _H_COM_DIAG_CONCHA_STREAMSINK_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Sink.h"
#include <stdio.h>

typedef struct StreamSink {

    /**
     * Base class.
     */
	Sink sink;

    /**
     * Pointer to standard I/O stream.
     */
    FILE * stream;

} StreamSink;

/**
 * Open a Stream Sink. The Sink consumes octets to a standard I/O stream.
 * @param that points to the Stream Sink.
 * @param stream is an standard I/O stream opened for writing.
 * @return a pointer to the Stream Source as a Source.
 */
extern Sink * openStreamSink(StreamSink * that, FILE * stream);

/**
 * Write an octet of data to the Sink.
 * @param that points to the Sink.
 * @param data is an octet to write into the Sink.
 * @return data as an integer for success, <0 otherwise.
 */
extern int writeStreamSink(Sink * that, char data);

/**
 * Close the Sink. This calls fclose(3) on the stream.
 * @param that points to the Sink.
 * @return 0 for success, <0 otherwise.
 */
extern int closeStreamSink(Sink * that);

#endif
