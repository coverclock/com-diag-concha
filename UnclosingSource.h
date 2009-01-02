/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_UNCLOSINGSOURCE_
#define _H_COM_DIAG_CONCHA_UNCLOSINGSOURCE_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"

typedef struct UnclosingSource {

    /**
     * Base class.
     */
	Source source;

    /**
     * Pointer to primary Source.
     */
	Source * primary;

} UnclosingSource;

/**
 * Open a Unclosing Source. The Source forwards all methods to the primary
 * Source except for the close. This causes the primary Source to be left open
 * even if an application closes the Unclosing Source.
 * @param that points to the Unclosing Source.
 * @param primary points to the primary Source.
 * @return a pointer to the Unclosing Source as a Source.
 */
extern Source * openUnclosingSource(UnclosingSource * that, Source * primary);

/**
 * Read an octet of data from the Source. An octet is returned from the
 * primary Source.
 * @param that points to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int readUnclosingSource(Source * that);

/**
 * Push an octet of data back into the Source. The octet is pushed back
 * onto the primary Source.
 * @param that points to the Source.
 * @param data is an octet to push back to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int pushBoundedSource(Source * that, char data);

/**
 * Close the Source. This has no effect on the primary Source.
 * @param that points to the Source.
 * @return 0 for success, <0 otherwise.
 */
extern int closeUnclosingSource(Source * that);

#endif
