/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_SPANNINGSOURCE_
#define _H_COM_DIAG_CONCHA_SPANNINGSOURCE_

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"
#include <sys/types.h>

typedef struct SpanningSource SpanningSource;

typedef struct SpanningSourceVirtualTable {

    /**
     * Base class virtual table.
     */
    SourceVirtualTable base;

    /**
     * Pointer to read Spanning Source function.
     */
	ssize_t (*read)(SpanningSource * that, void * buffer, size_t size);

    /**
     * Pointer to close Spanning Source function.
     */
	int (*close)(SpanningSource * that);

} SpanningSourceVirtualTable;

struct SpanningSource {

    /**
     * Pointer to SpanningSource virtual table.
     */
    SpanningSourceVirtualTable * vp;

};

/**
 * Read one or more octets of data from the Spanning Source. Whether this call
 * blocks the caller depends on the underlying implementation.
 * @param that points to the Spanning Source.
 * @param buffer points to the buffer into which octets are read.
 * @param size is the number of octets to read.
 * @return the number of octets actually read for success, <0 otherwise.
 */
extern ssize_t readSpanningSource(SpanningSource * that, void * buffer, size_t size);

/**
 * Close the SpanningSource. What this means depends upon the Spanning Source.
 * Operations performed on a closed Spanning Source are undefined.
 * @param that points to the Spanning Source.
 * @return 0 for success, <0 otherwise.
 */
extern int closeSpanningSource(SpanningSource * that);

#endif
