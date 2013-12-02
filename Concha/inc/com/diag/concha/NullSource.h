/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_NULLSOURCE_
#define _H_COM_DIAG_CONCHA_NULLSOURCE_

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

typedef struct NullSource {

    /**
     * Base class.
     */
	Source source;

} NullSource;

/**
 * Open a Null Source. The Source never accepts octets of data.
 * @param that points to the Null Source.
 * @return a pointer to the Null Source as a Source.
 */
extern Source * openNullSource(NullSource * that);

#endif
