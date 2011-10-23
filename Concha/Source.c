/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/Source.h"

int readSource(Source * that) {
	return (*(that->vp->read))(that);
}

int pushSource(Source * that, char data) {
	return (*(that->vp->push))(that, data);
}

int closeSource(Source * that) {
	return (*(that->vp->close))(that);
}

size_t readsSource(Source * that, void * buffer, size_t size) {
    size_t reads = 0;
    char * here = (char *)buffer;
    int rc;

    while ((size--) > 0) {
        if ((rc = readSource(that)) < 0) {
            break;
        }
        here[reads++] = rc;
    }

    return reads;
}
