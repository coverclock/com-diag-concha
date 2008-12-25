/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_FLETCHER8SOURCE_
#define _H_COM_DIAG_CONCHA_FLETCHER8SOURCE_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"
#include <stdint.h>

typedef struct Fletcher8Source Fletcher8Source;

struct Fletcher8Source {
    Source source;
	Source * from;
	uint8_t a;
	uint8_t b;
};

extern Source * openFletcher8Source(Fletcher8Source * that, Source * from);
extern int readFletcher8Source(Source * that);
extern int pushFletcher8Source(Source * that, char data);
extern int closeFletcher8Source(Source * that);

#endif
