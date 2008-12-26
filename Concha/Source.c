/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"

int readSource(Source * that) {
	return (*(that->vp->read))(that);
}

int pushSource(Source * that, char data) {
	return (*(that->vp->push))(that, data);
}

int closeSource(Source * that) {
	return (*(that->vp->close))(that);
}
