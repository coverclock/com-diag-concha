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
    if (tp->eof) {
        data = EOF;
    } else if ((data == readSource(tp->primary)) == EOF) {
        tp->eof = !0;
    } else {
        tp->x = tp->y;
        tp->y = tp->z;
        tp->z = (unsigned char)data;
        tp->a += tp->x;
        tp->b += tp->a;
        data = tp->x;
    }
	return data;
}

int pushFletcher8Source(Source * that, char data) {
	Fletcher8Source * tp = (Fletcher8Source *)that;
    int rc;
    rc = pushSource(tp->primary, (unsigned char)tp->z);
    if (rc != EOF) {
        tp->z = tp->y;
        tp->y = tp->x;
        tp->x = (unsigned char)data;
        tp->b -= tp->a;
        tp->a -= tp->x;
        rc = tp->x; 
    }
    return rc;
}

int closeFletcher8Source(Source * that) {
	Fletcher8Source * tp = (Fletcher8Source *)that;
    int rc;
    int result = 0;
	if ((rc = closeSource(tp->primary)) < 0) {
        result = rc;
    }
    if ((tp->a != tp->y) || (tp->b != tp->z)) {
        result = EOF;
    }
    return result;
}

static SourceVirtualTable vtable = {
	readFletcher8Source,
	pushFletcher8Source,
	closeFletcher8Source
};

Source * openFletcher8Source(Fletcher8Source * that, Source * primary) {
	that->source.vp = &vtable;
    that->primary = primary;
    that->eof = 0;
	that->a = 0;
	that->b = 0;
    that->x = EOF;
    that->y = EOF;
    if ((that->z = readSource(that->primary)) != EOF) {
        that->y = that->z;
        that->z = readSource(that->primary);
    }
	return (Source *)that;
}
