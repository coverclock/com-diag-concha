/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/UnclosingSource.h"

int readUnclosingSource(Source * that) {
	UnclosingSource * tp = (UnclosingSource *)that;

	return readSource(tp->primary);
}

int pushUnclosingSource(Source * that, char data) {
	UnclosingSource * tp = (UnclosingSource *)that;

    return pushSource(tp->primary, data);
}

int closeUnclosingSource(Source * that) {
	return 0;
}

static SourceVirtualTable vtable = {
	readUnclosingSource,
	pushUnclosingSource,
	closeUnclosingSource
};

Source * openUnclosingSource(UnclosingSource * that, Source * primary) {

    if ((that == (UnclosingSource *)0) || (primary == (Source *)0)) {
        return (Source *)0;
    }

	that->source.vp = &vtable;
	that->primary = primary;

	return (Source *)that;
}
