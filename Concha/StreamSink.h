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
	Sink sink;
    FILE * stream;
} StreamSink;

extern Sink * openStreamSink(StreamSink * that, FILE * stream);
extern int writeStreamSink(Sink * that, char data);
extern int closeStreamSink(Sink * that);

#endif
