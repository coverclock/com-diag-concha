/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_STREAMSOURCE_
#define _H_COM_DIAG_CONCHA_STREAMSOURCE_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"
#include <stdio.h>

typedef struct StreamSource {
	Source source;
    FILE * stream;
} StreamSource;

extern Source * openStreamSource(StreamSource * that, FILE * stream);
extern int readStreamSource(Source * that);
extern int pushStreamSource(Source * that, char data);
extern int closeStreamSource(Source * that);

#endif
