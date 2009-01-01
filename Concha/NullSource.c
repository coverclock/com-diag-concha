/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "NullSource.h"

int readNullSource(Source * that) {
	return EOF;
}

int pushNullSource(Source * that, char data) {
	return EOF;
}

int closeNullSource(Source * that) {
	return 0;
}

static SourceVirtualTable vtable = {
	readNullSource,
	pushNullSource,
	closeNullSource
};

Source * openNullSource(NullSource * that) {
	that->source.vp = &vtable;

	return (Source *)that;
}
