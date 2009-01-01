/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "BoundedSource.h"

int readBoundedSource(Source * that) {
	BoundedSource * tp = (BoundedSource *)that;
    int data = EOF;
    if (tp->bound == 0) {
        /* Do nothing. */
    } else if ((data = readSource(tp->primary)) == EOF) {
        /* Do nothing. */
    } else {
        --tp->bound;
    }
    return data;
}

int pushBoundedSource(Source * that, char data) {
	BoundedSource * tp = (BoundedSource *)that;
    int rc;
    if ((rc = pushSource(tp->primary, data)) != EOF) {
        ++tp->bound;
    }
	return rc;
}

int closeBoundedSource(Source * that) {
	return 0;
}

static SourceVirtualTable vtable = {
	readBoundedSource,
	pushBoundedSource,
	closeBoundedSource
};

Source * openBoundedSource(BoundedSource * that, Source * primary, size_t bound) {
	that->source.vp = &vtable;
	that->primary = primary;
	that->bound = bound;
	return (Source *)that;
}

