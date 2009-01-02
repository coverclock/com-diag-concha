/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "ClosingSink.h"

int writeClosingSink(Sink * that, char data) {
	ClosingSink * tp = (ClosingSink *)that;
    int rc;

    if (tp->closed) {
        rc = EOF;
    } else if (tp->ended) {
        rc = EOF;
    } else if ((rc = writeSink(tp->primary, data)) == EOF) {
        tp->ended = !0;
    } else {
        /* Do nothing. */
    }

	return rc;
}

int closeClosingSink(Sink * that) {
	ClosingSink * tp = (ClosingSink *)that;
    int rc;

    if (tp->closed) {
        rc = EOF;
    } else if ((rc = closeSink(tp->primary)) == 0) {
        tp->closed = !0;
    } else {
        /* Do nothing. */
    }

    return rc;
}

static SinkVirtualTable vtable = {
	writeClosingSink,
	closeClosingSink
};

Sink * openClosingSink(ClosingSink * that, Sink * primary) {

	that->sink.vp = &vtable;
	that->primary = primary;
    that->ended = 0;
    that->closed = 0;

	return (Sink *)that;
}
