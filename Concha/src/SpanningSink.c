/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/SpanningSink.h"

ssize_t writeSpanningSink(SpanningSink * that, const void * buffer, size_t size) {
	return (*(that->vp->write))(that, buffer, size);
}

int closeSpanningSink(SpanningSink * that) {
    Sink * tp = (Sink *)that;

    return (*(tp->vp->close))(tp);
}
