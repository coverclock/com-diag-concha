/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_NULLSOURCE_
#define _H_COM_DIAG_CONCHA_NULLSOURCE_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"
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

/**
 * Read an octet of data from the Source. The Null Source always returns
 * EOF.
 * @param that points to the Source.
 * @return EOF always.
 */
extern int readNullSource(Source * that);

/**
 * Push an octet of data back into the Source. The Null Source always
 * returns EOF.
 * @param that points to the Source.
 * @param data is an octet to push back to the Source.
 * @return EOF always.
 */
extern int pushNullSource(Source * that, char data);

/**
 * Close the Source. This has no effect on the Null Source.
 * @param that points to the Source.
 * @return 0 always.
 */
extern int closeNullSource(Source * that);

#endif
