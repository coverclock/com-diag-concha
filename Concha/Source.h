/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_SOURCE_
#define _H_COM_DIAG_CONCHA_SOURCE_

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
 * Read an octet of data from the Source.
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

#endif
