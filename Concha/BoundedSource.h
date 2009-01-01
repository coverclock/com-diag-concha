/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_BOUNDEDSOURCE_
#define _H_COM_DIAG_CONCHA_BOUNDEDSOURCE_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"

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

/**
 * Read an octet of data from the Source.
 * @param that points to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int readBoundedSource(Source * that);

/**
 * Push an octet of data back into the Source. It will be the next octet
 * read from the Source. Only one octet can be pushed back before being
 * re-read from the Source. The octet is not literally pushed back into
 * the underlying storage medium.
 * @param that points to the Source.
 * @param data is an octet to push back to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int pushBoundedSource(Source * that, char data);

/**
 * Close the Source. This has no effect on the Bounded Source.
 * @param that points to the Source.
 * @return 0 for success, <0 otherwise.
 */
extern int closeBoundedSource(Source * that);

#endif

