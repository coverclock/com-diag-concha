/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_COMPOSITESOURCE_
#define _H_COM_DIAG_CONCHA_COMPOSITESOURCE_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/Source.h"

typedef struct CompositeSource {

    /**
     * Base class.
     */
	Source source;

    /**
     * Pointer to currently active Source.
     */
    Source * active;

    /**
     * Pointer to primary Source.
     */
	Source * primary;

    /**
     * Pointer to secondary Source.
     */
	Source * secondary;

} CompositeSource;

/**
 * Open a Composite Source. The Source is the concatenation of a primary
 * Source and a secondary Source.
 * @param that points to the Composite Source.
 * @param primary points to the primary Source.
 * @param secondary points to the secondary Source.
 * @return a pointer to the Composite Source as a Source.
 */
extern Source * openCompositeSource(CompositeSource * that, Source * primary, Source * secondary);

#endif
