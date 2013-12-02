/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/ClosingSource.h"

int readClosingSource(Source * that) {
	ClosingSource * tp = (ClosingSource *)that;
    int data;

    if (tp->closed) {
        data = EOF;
    } else if (tp->ended) {
        data = EOF;
    } else if ((data = readSource(tp->primary)) == EOF) {
        tp->ended = !0;
    } else {
        /* Do nothing. */
    }

	return data;
}

int pushClosingSource(Source * that, char data) {
	ClosingSource * tp = (ClosingSource *)that;
    int rc;

    if (tp->closed) {
        rc = EOF;
    } else if (tp->ended) {
        rc = EOF;
    } else if ((rc = pushSource(tp->primary, data)) == EOF) {
        tp->ended = !0;
    } else {
        /* Do nothing. */
    }

    return rc;
}

int closeClosingSource(Source * that) {
	ClosingSource * tp = (ClosingSource *)that;
    int rc;

    if (tp->closed) {
        rc = EOF;
    } else if ((rc = closeSource(tp->primary)) == 0) {
        tp->closed = !0;
    } else {
        /* Do nothing. */
    }

    return rc;
}

static SourceVirtualTable vtable = {
	readClosingSource,
	pushClosingSource,
	closeClosingSource
};

Source * openClosingSource(ClosingSource * that, Source * primary) {

    if ((that == (ClosingSource *)0) || (primary == (Source *)0)) {
        return (Source *)0;
    }

	that->source.vp = &vtable;
	that->primary = primary;
    that->ended = 0;
    that->closed = 0;

	return (Source *)that;
}
