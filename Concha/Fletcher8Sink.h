/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_FLETCHER8SINK_
#define _H_COM_DIAG_CONCHA_FLETCHER8SINK_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Sink.h"
#include <stdint.h>

typedef struct Fletcher8Sink Fletcher8Sink;

struct Fletcher8Sink {
	Sink sink;
    Sink * to;
    uint8_t a;
    uint8_t b;
};

extern Sink * openFletcher8Sink(Fletcher8Sink * that, Sink * to);
extern int writeFletcher8Sink(Sink * that, char data);
extern int closeFletcher8Sink(Sink * that);

#endif
