/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "SpanningSource.h"

ssize_t readSpanningSource(SpanningSource * that, void * buffer, size_t size) {
	return (*(that->vp->read))(that, buffer, size);
}

int closeSpanningSource(SpanningSource * that) {
    Source * tp = (Source *)that;

	return (*(tp->vp->close))(tp);
}
