/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "NullSink.h"

int writeNullSink(Sink * that, char data) {
	return data;
}

int closeNullSink(Sink * that) {
	return 0;
}

static SinkVirtualTable vtable = {
	writeNullSink,
	closeNullSink
};

Sink * openNullSink(NullSink * that) {
	that->sink.vp = &vtable;

	return (Sink *)that;
}
