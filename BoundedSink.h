/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_BOUNDEDSINK_
#define _H_COM_DIAG_CONCHA_BOUNDEDSINK_

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
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
	Sink sink;

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

#endif
