/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_STREAMSINK_
#define _H_COM_DIAG_CONCHA_STREAMSINK_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/Sink.h"
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

#endif
