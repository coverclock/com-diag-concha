/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_SPANNINGSINK_
#define _H_COM_DIAG_CONCHA_SPANNINGSINK_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/Sink.h"
#include <sys/types.h>

typedef struct SpanningSink SpanningSink;

typedef struct SpanningSinkVirtualTable {

    /**
     * Base class virtual table.
     */
    SinkVirtualTable base;

    /**
     * Pointer to write Spanning Sink function.
     */
	ssize_t (*write)(SpanningSink * that, const void * buffer, size_t size);

} SpanningSinkVirtualTable;

struct SpanningSink {

    /**
     * Pointer to Spanning Sink virtual table.
     */
    SpanningSinkVirtualTable * vp;

};

/**
 * Write one or more octets to the Spanning Sink. Whether this call blocks
 * the caller depends on the underlying implementation.
 * @param that points to the Spanning Sink.
 * @param buffer points to the buffer from which octets are written.
 * @param size is the number of octets to write.
 * @return the number of octets actually written for success, <0 otherwise.
 */
extern ssize_t writeSpanningSink(SpanningSink * that, const void * buffer, size_t size);

/**
 * Close the SpanningSink. What this means depends upon the Spanning Sink.
 * Operations performed on a closed Spanning Sink are undefined.
 * @param that points to the Spanning Sink.
 * @return 0 for success, <0 otherwise.
 */
extern int closeSpanningSink(SpanningSink * that);

#endif
