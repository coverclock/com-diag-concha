/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_COMPOSITESOURCE_
#define _H_COM_DIAG_CONCHA_COMPOSITESOURCE_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"

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

/**
 * Read an octet of data from the Source. Each octet of the primary Source
 * is returned. Once the primary Source is exhausted, each octet of the
 * secondary Source is returned. EOF is returned when the secondary Source
 * is exhaused.
 * @param that points to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int readCompositeSource(Source * that);

/**
 * Push an octet of data back into the Source. It will be the next octet
 * read from the Source. Only one octet can be pushed back before being
 * re-read from the Source. The octet is not literally pushed back into
 * the underlying storage medium.
 * @param that points to the Source.
 * @param data is an octet to push back to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int pushCompositeSource(Source * that, char data);

/**
 * Close the Source. The primary Source and the secondary Source is closed.
 * @param that points to the Source.
 * @return 0 for success, <0 otherwise.
 */
extern int closeCompositeSource(Source * that);

#endif
