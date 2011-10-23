/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_UNCLOSINGSOURCE_
#define _H_COM_DIAG_CONCHA_UNCLOSINGSOURCE_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/Source.h"

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

#endif
