/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "UnclosedSink.h"

int writeUnclosedSink(Sink * that, char data) {
	UnclosedSink * tp = (UnclosedSink *)that;

	return writeSink(tp->primary, data);
}

int closeUnclosedSink(Sink * that) {
    return 0;
}

static SinkVirtualTable vtable = {
	writeUnclosedSink,
	closeUnclosedSink
};

Sink * openUnclosedSink(UnclosedSink * that, Sink * primary) {

	that->sink.vp = &vtable;
	that->primary = primary;

	return (Sink *)that;
}
