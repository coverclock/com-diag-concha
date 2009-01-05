/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_SPANNINGSINK_
#define _H_COM_DIAG_CONCHA_SPANNINGSINK_

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Sink.h"
#include <sys/types.h>

typedef struct SpanningSink SpanningSink;

typedef struct SpanningSinkVirtualTable {

    /**
     * Base class virtual table.
     */
    SinkVirtualTable base;

    /**
     * Pointer to write Sink function.
     */
	ssize_t (*write)(SpanningSink * that, const void * buffer, size_t size);

    /**
     * Pointer to close Sink function.
     */
	int (*close)(SpanningSink * that);

} SpanningSinkVirtualTable;

struct SpanningSink {

    /**
     * Pointer to Sink virtual table.
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
 * Close the Spanning Sink. What this means depends on the Spanning Sink.
 * Operations performed on a closed Spanning Sink are undefined.
 * @param that points to the Spanning Sink.
 * @return 0 for success, <0 otherwise.
 */
extern int closeSpanningSink(SpanningSink * that);

#endif
