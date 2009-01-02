/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_CLOSINGSINK_
#define _H_COM_DIAG_CONCHA_CLOSINGSINK_

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

typedef struct ClosingSink {

    /**
     * Base class.
     */
	Sink sink;

    /**
     * Pointer to primary Sink.
     */
    Sink * primary;

    /**
     * True if closed or if write returned EOF, false otherwise.
     */
    int eof;

} ClosingSink;

/**
 * Open a Closing Sink. Once the Sink is closed, or the write of the
 * primary Sink returns EOF, the Sink guarantees that EOF is returned
 * henceforth.  This is useful for certain underlying platform
 * implementations for which EOF is an intermittent condition. It also
 * guarantees that the primary Sink write and close are never called
 * after EOF or close.
 * @param that points to the Closing Sink.
 * @param primary points to a primary Sink.
 * @return a pointer to the Descriptor Source as a Source.
 */
extern Sink * openClosingSink(ClosingSink * that, Sink * primary);

/**
 * Write an octet of data to the Sink. The octet is written to the
 * primary Sink. If an EOF is encountered, the Sink is permanently
 * placed in the EOF state.
 * @param that points to the Sink.
 * @param data is an octet to write into the Sink.
 * @return data as an integer for success, <0 otherwise.
 */
extern int writeBufferSink(Sink * that, char data);

/**
 * Close the Sink. The Sink closes the primary Sink. If the close of
 * the primary Sink succeeds, the Sink is permanently placed in the
 * EOF state.
 * @param that points to the Sink.
 * @return 0 for success, <0 otherwise.
 */
extern int closeClosingSink(Sink * that);

#endif
