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

/**
 * Open a Null Sink. The Sink always accepts data octets.
 * @param that points to the Null Sink.
 * @return a pointer to the Null Sink as a Sink.
 */
extern Sink * openNullSink(NullSink * that);

/**
 * Write an octet of data to the Sink.
 * @param that points to the Sink.
 * @param data is an octet to write into the Sink.
 * @return data as an integer always.
 */
extern int writeNullSink(Sink * that, char data);

/**
 * Close the Sink. This has no effect on the Null Sink.
 * @param that points to the Sink.
 * @return 0 always.
 */
extern int closeNullSink(Sink * that);

#endif
