/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_BOUNDEDSINK_
#define _H_COM_DIAG_CONCHA_BOUNDEDSINK_

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

typedef struct BoundedSink {

    /**
     * Base class.
     */
	Sink source;

    /**
     * Pointer to primary Sink.
     */
    Sink * primary;

    /**
     * Bound of the Sink in octets.
     */
	size_t bound;

} BoundedSink;

/**
 * Open a Bounded Sink. The Sink will cosume octets until its bound is
 * reached.
 * @param that points to the Bounded Sink.
 * @param primary points to the primary Sink.
 * @param bound is the bound of the Sink in octets.
 * @return a pointer to the Bounded Sink as a Sink.
 */
extern Sink * openBoundedSink(BoundedSink * that, Sink * primary, size_t bound);

/**
 * Write an octet of data back into the Sink.
 * @param that points to the Sink.
 * @param data is an octet to write to the Sink.
 * @return data as an integer for success, <0 otherwise.
 */
extern int writeBoundedSink(Sink * that, char data);

/**
 * Close the Sink. This primary Sink is closed.
 * @param that points to the Sink.
 * @return 0 for success, <0 otherwise.
 */
extern int closeBoundedSink(Sink * that);

#endif
