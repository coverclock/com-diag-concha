/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_UNCLOSINGSINK_
#define _H_COM_DIAG_CONCHA_UNCLOSINGSINK_

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

typedef struct UnclosingSink {

    /**
     * Base class.
     */
	Sink sink;

    /**
     * Pointer to primary Sink.
     */
    Sink * primary;

} UnclosingSink;

/**
 * Open a Unclosing Sink. The Sink forwards all methods to the primary
 * Sink except for the close. This causes the primary Sink to be left open
 * even if an application closes the Unclosing Sink.
 * @param that points to the Unclosing Sink.
 * @param primary points to a primary Sink.
 * @return a pointer to the Descriptor Source as a Source.
 */
extern Sink * openUnclosingSink(UnclosingSink * that, Sink * primary);

#endif
