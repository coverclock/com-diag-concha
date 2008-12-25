/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Fletcher8Source.h"

int readFletcher8Source(Source * that) {
	Fletcher8Source * tp = (Fletcher8Source *)that;
    int data;
    data = readSource(tp->from);
    if (data != EOF) {
        tp->a += (unsigned char)data;
        tp->b += tp->a;
    }
	return data;
}

int pushFletcher8Source(Source * that, char data) {
	Fletcher8Source * tp = (Fletcher8Source *)that;
    tp->b -= tp->a;
    tp->a -= (unsigned char)data;
    return pushSource(tp->from, data);
}

int closeFletcher8Source(Source * that) {
	Fletcher8Source * tp = (Fletcher8Source *)that;
	return closeSource(tp->from);
}

Source * openFletcher8Source(Fletcher8Source * that, Source * from) {
	that->source.read = &readFletcher8Source;
	that->source.push = &pushFletcher8Source;
	that->source.close = &closeFletcher8Source;
	that->a = 0;
	that->b = 0;
	return (Source *)that;
}
