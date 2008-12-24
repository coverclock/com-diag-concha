/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_SINK_
#define _H_COM_DIAG_CONCHA_SINK_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include <stdint.h>

#ifndef EOF
#define EOF (-1)
#endif

typedef struct Sink Sink;

struct Sink {
	int (*write)(Sink * that, char data);
	int (*close)(Sink * that);
};

extern int writeSink(Sink * that, char data);
extern int closeSink(Sink * that);

#endif