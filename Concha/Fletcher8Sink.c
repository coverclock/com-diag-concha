/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Fletcher8Sink.h"

int writeFletcher8Sink(Sink * that, char data) {
	Fletcher8Sink * tp = (Fletcher8Sink *)that;
	tp->a += data;
	tp->b += tp->a;
	return writeSink(tp->to, data);
}

int closeFletcher8Sink(Sink * that) {
	Fletcher8Sink * tp = (Fletcher8Sink *)that;
	return closeSink(tp->to);
}

static SinkVirtualTable vtable = {
	writeFletcher8Sink,
	closeFletcher8Sink
};

Sink * openFletcher8Sink(Fletcher8Sink * that, Sink * to) {
	that->sink.vp = &vtable;
	that->to = to;
	that->a = 0;
	that->b = 0;
	return (Sink *)that;
}
