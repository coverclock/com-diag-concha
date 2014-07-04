/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_BOUNDEDSOURCE_
#define _H_COM_DIAG_CONCHA_BOUNDEDSOURCE_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/Source.h"
#include <sys/types.h>

typedef struct BoundedSource {

    /**
     * Base class.
     */
	Source source;

    /**
     * Pointer to primary Source.
     */
    Source * primary;

    /**
     * Bound of the Source in octets.
     */
	size_t bound;

} BoundedSource;

/**
 * Open a Bounded Source. The Source will produce octets until its bound is
 * reached.
 * @param that points to the Bounded Sink.
 * @param primary points to the primary Source.
 * @param bound is the bound of the Source in octets.
 * @return a pointer to the Bounded Sink as a Sink.
 */
extern Source * openBoundedSource(BoundedSource * that, Source * primary, size_t bound);

#endif
