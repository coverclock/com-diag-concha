/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/NullSink.h"

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

    if (that == (NullSink *)0) {
        return (Sink *)0;
    }

	that->sink.vp = &vtable;

	return (Sink *)that;
}
