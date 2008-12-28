/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_NULLSOURCE_
#define _H_COM_DIAG_CONCHA_NULLSOURCE_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"
#include <sys/types.h>

typedef struct NullSource {
	Source source;
} NullSource;

extern Source * openNullSource(NullSource * that);
extern int readNullSource(Source * that);
extern int pushNullSource(Source * that, char data);
extern int closeNullSource(Source * that);

#endif