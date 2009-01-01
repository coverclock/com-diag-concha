/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_UNCLOSEDSINK_
#define _H_COM_DIAG_CONCHA_UNCLOSEDSINK_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Sink.h"
#include <sys/types.h>

typedef struct UnclosedSink {

    /**
     * Base class.
     */
	Sink sink;

    /**
     * Pointer to primary Sink.
     */
    Sink * primary;

} UnclosedSink;

/**
 * Open a Unclosed Sink. The Sink inherits all methods from the primary
 * Sink except for the close.
 * @param that points to the Unclosed Sink.
 * @param primary points to a primary Sink.
 * @return a pointer to the Descriptor Source as a Source.
 */
extern Sink * openUnclosedSink(UnclosedSink * that, Sink * primary);

/**
 * Write an octet of data to the Sink. The octet is written to the
 * primary Sink.
 * @param that points to the Sink.
 * @param data is an octet to write into the Sink.
 * @return data as an integer for success, <0 otherwise.
 */
extern int writeBufferSink(Sink * that, char data);

/**
 * Close the Sink. This has no effect on the primary Sink.
 * @param that points to the Sink.
 * @return 0 for success, <0 otherwise.
 */
extern int closeUnclosedSink(Sink * that);

#endif
