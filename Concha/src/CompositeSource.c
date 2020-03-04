/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2020 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/CompositeSource.h"

int readCompositeSource(Source * that) {
	CompositeSource * tp = (CompositeSource *)that;
    int data;

    data = readSource(tp->active);
    if ((data == EOF) && (tp->active == tp->primary)) {
        tp->active = tp->secondary;
        data = readSource(tp->active);
    }

	return data;
}

int pushCompositeSource(Source * that, char data) {
	CompositeSource * tp = (CompositeSource *) that;

    return pushSource(tp->active, data);
}

int closeCompositeSource(Source * that) {
	CompositeSource * tp = (CompositeSource *) that;
    int pri;
    int sec;

    pri = closeSource(tp->primary);
    sec = closeSource(tp->secondary);

    return ((pri == EOF) || (sec == EOF)) ? EOF : 0;
}

static SourceVirtualTable vtable = {
	readCompositeSource,
	pushCompositeSource,
	closeCompositeSource
};

Source * openCompositeSource(CompositeSource * that, Source * primary, Source * secondary) {

    if ((that == (CompositeSource *)0) || (primary == (Source *)0) || (secondary == (Source *)0)) {
        return (Source *)0;
    }

	that->source.vp = &vtable;
	that->active = primary;
	that->primary = primary;
	that->secondary = secondary;

	return (Source *)that;
}
