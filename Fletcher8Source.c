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
        tp->x = tp->y;
        tp->y = tp->z;
        tp->z = data;
        tp->a += (unsigned char)data;
        tp->b += tp->a;
    } else if (tp->eof != EOF) {
        tp->eof = EOF;
        tp->b -= tp->a;
        tp->a -= tp->z;
        tp->b -= tp->a;
        tp->a -= tp->y;
    }
	return data;
}

int pushFletcher8Source(Source * that, char data) {
	Fletcher8Source * tp = (Fletcher8Source *)that;
    tp->z = tp->y;
    tp->y = tp->x;
    tp->x = '\0';
    tp->b -= tp->a;
    tp->a -= (unsigned char)data;
    return pushSource(tp->from, data);
}

int closeFletcher8Source(Source * that) {
	Fletcher8Source * tp = (Fletcher8Source *)that;
    int rc;
    int result = 0;
    if ((tp->a != tp->y) || (tp->b != tp->z)) {
        result = EOF;
    }
	if ((rc = closeSource(tp->from)) < 0) {
        result = rc;
    }
    return result;
}

static SourceVirtualTable vtable = {
	readFletcher8Source,
	pushFletcher8Source,
	closeFletcher8Source
};

Source * openFletcher8Source(Fletcher8Source * that, Source * from) {
	that->source.vp = &vtable;
    that->from = from;
    that->eof = !EOF;
    that->x = '\0';
    that->y = '\0';
    that->z = '\0';
	that->a = 0;
	that->b = 0;
	return (Source *)that;
}
