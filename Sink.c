/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Sink.h"

int writeSink(Sink * that, char data) {
	return (*(that->vp->write))(that, data);
}

int closeSink(Sink * that) {
	return (*(that->vp->close))(that);
}

size_t writesSink(Sink * that, const void * buffer, size_t size) {
    size_t writes = 0;
    char * here = (char *)buffer;

    while ((size--) > 0) {
        if (writeSink(that, here[writes]) < 0) {
            break;
        }
        writes++;
    }

    return writes;
}
