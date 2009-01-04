/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "UnclosingSink.h"

int writeUnclosingSink(Sink * that, char data) {
	UnclosingSink * tp = (UnclosingSink *)that;

	return writeSink(tp->primary, data);
}

int closeUnclosingSink(Sink * that) {
    return 0;
}

static SinkVirtualTable vtable = {
	writeUnclosingSink,
	closeUnclosingSink
};

Sink * openUnclosingSink(UnclosingSink * that, Sink * primary) {

    if ((that == (UnclosingSink *)0) || (primary == (Sink *)0)) {
        return (Sink *)0;
    }

	that->sink.vp = &vtable;
	that->primary = primary;

	return (Sink *)that;
}
