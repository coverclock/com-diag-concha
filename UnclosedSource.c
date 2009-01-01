/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "UnclosedSource.h"

int readUnclosedSource(Source * that) {
	UnclosedSource * tp = (UnclosedSource *)that;

	return readSource(tp->primary);
}

int pushUnclosedSource(Source * that, char data) {
	UnclosedSource * tp = (UnclosedSource *)that;

    return pushSource(tp->primary, data);
}

int closeUnclosedSource(Source * that) {
	return 0;
}

static SourceVirtualTable vtable = {
	readUnclosedSource,
	pushUnclosedSource,
	closeUnclosedSource
};

Source * openUnclosedSource(UnclosedSource * that, Source * primary) {

	that->source.vp = &vtable;
	that->primary = primary;

	return (Source *)that;
}
