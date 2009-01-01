/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "ExpanderSink.h"

int writeExpanderSink(Sink * that, char data) {
	ExpanderSink * tp = (ExpanderSink *)that;
    int pri = 0;
    int sec = 0;

    if (tp->primary != (Sink *)0) {
        pri = writeSink(tp->primary, data);
    }
    if (tp->secondary != (Sink *)0) {
        sec = writeSink(tp->secondary, data);
    }

    return ((pri == EOF) || (sec == EOF)) ? EOF : (unsigned char)data;
}

int closeExpanderSink(Sink * that) {
	ExpanderSink * tp = (ExpanderSink *)that;
    int pri = 0;
    int sec = 0;

    if (tp->primary != (Sink *)0) {
        pri = closeSink(tp->primary);
    }
    if (tp->secondary != (Sink *)0) {
        sec = closeSink(tp->secondary);
    }

    return ((pri == EOF) || (sec == EOF)) ? EOF : 0;
}

static SinkVirtualTable vtable = {
	writeExpanderSink,
	closeExpanderSink
};

Sink * openExpanderSink(ExpanderSink * that, Sink * primary, Sink * secondary) {

	that->sink.vp = &vtable;
	that->primary = primary;
	that->secondary = secondary;

	return (Sink *)that;
}
