/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "BoundedSink.h"

int writeBoundedSink(Sink * that, char data) {
	BoundedSink * tp = (BoundedSink *)that;
    int rc;

    if (tp->bound == 0) {
        rc = EOF;
    } else if ((rc = writeSink(tp->primary, data)) < 0) {
        /* Do nothing. */
    } else {
        --tp->bound;
    }

    return rc;
}

int closeBoundedSink(Sink * that) {
	BoundedSink * tp = (BoundedSink *)that;

	return closeSink(tp->primary);
}

static SinkVirtualTable vtable = {
	writeBoundedSink,
	closeBoundedSink
};

Sink * openBoundedSink(BoundedSink * that, Sink * primary, size_t bound) {

    if ((that == (BoundedSink *)0) || (primary == (Sink *)0)) {
        return (Sink *)0;
    }

	that->sink.vp = &vtable;
	that->primary = primary;
	that->bound = bound;

	return (Sink *)that;
}
