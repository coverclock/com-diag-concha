/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_FILESINK_
#define _H_COM_DIAG_CONCHA_FILESINK_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Sink.h"
#include <stdio.h>

typedef struct FileSink FileSink;

struct FileSink {
	Sink sink;
    FILE * stream;
};

extern Sink * openFileSink(FileSink * that, FILE * stream);
extern int writeFileSink(Sink * that, char data);
extern int closeFileSink(Sink * that);

#endif
