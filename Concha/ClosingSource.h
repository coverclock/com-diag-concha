/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_CLOSINGSOURCE_
#define _H_COM_DIAG_CONCHA_CLOSINGSOURCE_

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"

typedef struct ClosingSource {

    /**
     * Base class.
     */
	Source source;

    /**
     * Pointer to primary Source.
     */
	Source * primary;

    /**
     * True if read returned EOF, false otherwise.
     */
    int ended;

    /**
     *  True if closed, false otherwise.
     */
    int closed;

} ClosingSource;

/**
 * Open a Closing Source. Once the Source is closed, or a read or push of
 * the primary Source returns EOF, the Source guarantees that EOF is returned
 * henceforth.  This is useful for certain underlying platform
 * implementations for which EOF is an intermittent condition. It also
 * guarantees that the primary Sink read, push, and close are never called
 * after EOF or close.
 * @param that points to the Closing Source.
 * @param primary points to the primary Source.
 * @return a pointer to the Closing Source as a Source.
 */
extern Source * openClosingSource(ClosingSource * that, Source * primary);

#endif
