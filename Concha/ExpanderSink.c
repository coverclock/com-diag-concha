/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/ExpanderSink.h"

int writeExpanderSink(Sink * that, char data) {
	ExpanderSink * tp = (ExpanderSink *)that;
    int pri;
    int sec;

    pri = writeSink(tp->primary, data);
    sec = writeSink(tp->secondary, data);

    return ((pri == EOF) || (sec == EOF)) ? EOF : (unsigned char)data;
}

int closeExpanderSink(Sink * that) {
	ExpanderSink * tp = (ExpanderSink *)that;
    int pri;
    int sec;

    pri = closeSink(tp->primary);
    sec = closeSink(tp->secondary);

    return ((pri == EOF) || (sec == EOF)) ? EOF : 0;
}

static SinkVirtualTable vtable = {
	writeExpanderSink,
	closeExpanderSink
};

Sink * openExpanderSink(ExpanderSink * that, Sink * primary, Sink * secondary) {

    if ((that == (ExpanderSink *)0) || (primary == (Sink *)0) || (secondary == (Sink *)0)) {
        return (Sink *)0;
    }

	that->sink.vp = &vtable;
	that->primary = primary;
	that->secondary = secondary;

	return (Sink *)that;
}
