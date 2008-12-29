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

#include "Concha.h"
#include <sys/types.h>

typedef struct Sink Sink;

typedef struct SinkVirtualTable {
	int (*write)(Sink * that, char data);
	int (*close)(Sink * that);
} SinkVirtualTable;

struct Sink {
    SinkVirtualTable * vp;
};

/**
 * Write an octet of data to the Sink.
 * @param that points to the Sink.
 * @param data is an octet to write into the Sink.
 * @return data as an integer for success, <0 otherwise.
 */
extern int writeSink(Sink * that, char data);

/**
 * Close the Sink. What this means depends on the Sink. Operations
 * performed on a closed Sink are undefined.
 * @param that points to the Sink.
 * @return 0 for success, <0 otherwise.
 */
extern int closeSink(Sink * that);

#endif
