/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_SINK_
#define _H_COM_DIAG_CONCHA_SINK_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/Concha.h"

typedef struct Sink Sink;

typedef struct SinkVirtualTable {

    /**
     * Pointer to write Sink function.
     */
	int (*write)(Sink * that, char data);

    /**
     * Pointer to close Sink function.
     */
	int (*close)(Sink * that);

} SinkVirtualTable;

struct Sink {

    /**
     * Pointer to Sink virtual table.
     */
    SinkVirtualTable * vp;

};

/**
 * Write an octet of data to the Sink. Whether this call blocks the caller
 * depends on the underlying implementation.
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

/**
 * Extends writeSink to write multiple bytes by just calling writeSink
 * multiple times.
 * @param that points to the Source.
 * @param buffer points to the buffer from which data is written.
 * @param size is the size of the buffer in octets.
 * @return the number of octets actually written.
 */
extern size_t writesSink(Sink * that, const void * buffer, size_t size);

#endif
