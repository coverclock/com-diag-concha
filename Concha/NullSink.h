/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_NULLSINK_
#define _H_COM_DIAG_CONCHA_NULLSINK_

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

typedef struct NullSink {
	Sink sink;
} NullSink;

extern Sink * openNullSink(NullSink * that);
extern int writeNullSink(Sink * that, char data);
extern int closeNullSink(Sink * that);

#endif
