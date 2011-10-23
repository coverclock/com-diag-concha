/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_SOURCE_
#define _H_COM_DIAG_CONCHA_SOURCE_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/Concha.h"

typedef struct Source Source;

typedef struct SourceVirtualTable {

    /**
     * Pointer to read Source function.
     */
	int (*read)(Source * that);

    /**
     * Pointer to push Source function.
     */
	int (*push)(Source * that, char data);

    /**
     * Pointer to close Source function.
     */
	int (*close)(Source * that);

} SourceVirtualTable;

struct Source {

    /**
     * Pointer to Source virtual table.
     */
    SourceVirtualTable * vp;

};

/**
 * Read an octet of data from the Source. Whether this call blocks the
 * caller depends on the underlying implementation.
 * @param that points to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int readSource(Source * that);

/**
 * Push an octet of data back into the Source. It will be the next octet
 * read from the Source. Only one octet can be pushed back before being
 * re-read from the Source. The octet is not literally pushed back into
 * the underlying storage medium. Pushing back more than one octet before
 * re-reading is undefined.
 * @param that points to the Source.
 * @param data is an octet to push back to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int pushSource(Source * that, char data);

/**
 * Close the Source. What this means depends upon the Source. Operations
 * performed on a closed Source are undefined.
 * @param that points to the Source.
 * @return 0 for success, <0 otherwise.
 */
extern int closeSource(Source * that);

/**
 * Extends readSource to read multiple bytes by just calling readSource
 * multiple times.
 * @param that points to the Source.
 * @param buffer points to the buffer into which data is read.
 * @param size is the size of the buffer in octets.
 * @return the number of octets actually read.
 */
extern size_t readsSource(Source * that, void * buffer, size_t size);

#endif
