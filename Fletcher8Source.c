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

#define STATE_NEED2   (2)
#define STATE_NEED1   (1)
#define STATE_NEED0   (0)
#define STATE_EOF     (EOF)

int readFletcher8Source(Source * that) {
	Fletcher8Source * tp = (Fletcher8Source *)that;
    int complete = 0;
    int data;

    while (!complete) {

        switch (tp->state) {

        case STATE_NEED2:
            if ((data = readSource(tp->primary)) == EOF) {
                complete = !0;
                tp->state = STATE_EOF;
            } else if (data == EOR) {
                complete = !0;
            } else {
                tp->z = (unsigned char)data;
                tp->state = STATE_NEED1;
            }
            break;

        case STATE_NEED1:
            if ((data = readSource(tp->primary)) == EOF) {
                complete = !0;
                data = tp->z;
                tp->state = STATE_EOF;
            } else if (data == EOR) {
                complete = !0;
            } else {
                tp->y = tp->z;
                tp->z = (unsigned char)data;
                tp->state = STATE_NEED0;
            }
            break;

        case STATE_NEED0:
            if ((data = readSource(tp->primary)) == EOF) {
                complete = !0;
                tp->state = STATE_EOF;
            } else if (data == EOR) {
                complete = !0;
            } else {
                complete = !0;
                tp->x = tp->y;
                tp->y = tp->z;
                tp->z = (unsigned char)data;
                tp->a += tp->x;
                tp->b += tp->a;
                data = tp->x;
            }
            break;

        case STATE_EOF:
            complete = !0;
            data = EOF;
            break;

        }

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
    that->state = STATE_NEED2;
	that->a = 0;
	that->b = 0;
    that->x = EOF;
    that->y = EOF;
    that->z = EOF;
	return (Source *)that;
}
