/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "CompositeSource.h"

int readCompositeSource(Source * that) {
	CompositeSource * tp = (CompositeSource *)that;
    int data;
    data = readSource(tp->primary);
    if ((data == EOF) && (tp->secondary != (Source *)0)) {
        closeSource(tp->primary);
        tp->primary = tp->secondary;
        tp->secondary = (Source *)0;
        data = readSource(tp->primary);
    }
	return data;
}

int pushCompositeSource(Source * that, char data) {
	CompositeSource * tp = (CompositeSource *) that;
    return pushSource(tp->primary, data);
}

int closeCompositeSource(Source * that) {
	CompositeSource * tp = (CompositeSource *) that;
    closeSource(tp->primary);
    if (tp->secondary != (Source *)0) {
        closeSource(tp->secondary);
    }
	return 0;
}

static SourceVirtualTable vtable = {
	readCompositeSource,
	pushCompositeSource,
	closeCompositeSource
};

Source * openCompositeSource(CompositeSource * that, Source * primary, Source * secondary) {
	that->source.vp = &vtable;
	that->primary = primary;
	that->secondary = secondary;
	return (Source *)that;
}
