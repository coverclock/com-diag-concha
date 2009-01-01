/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_EXPANDERSINK_
#define _H_COM_DIAG_CONCHA_EXPANDERSINK_

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

typedef struct ExpanderSink {

    /**
     * Base class.
     */
	Sink sink;

    /**
     * Pointer to primary Sink.
     */
    Sink * primary;

    /**
     * Pointer to secondary Sink.
     */
    Sink * secondary;

} ExpanderSink;

/**
 * Open a Expander Sink. The Sink duplicates writes to a primary Sink and a
 * secondary Sink.
 * @param that points to the Expander Sink.
 * @param primary points to a primary Sink.
 * @param secondary points to a secondary Sink.
 * @return a pointer to the Descriptor SInk as a Sink.
 */
extern Sink * openExpanderSink(ExpanderSink * that, Sink * primary, Sink * secondary);

/**
 * Write an octet of data to the Sink. The octet of data is written to both
 * the primary Sink and the secondary Sink. Both writes must be successful
 * for the write to succeed.
 * @param that points to the Sink.
 * @param data is an octet to write into the Sink.
 * @return data as an integer for success, <0 otherwise.
 */
extern int writeExpanderSink(Sink * that, char data);

/**
 * Close the Sink. This closes both the primary and the secondary Sinks.
 * @param that points to the Sink.
 * @return 0 for success, <0 otherwise.
 */
extern int closeExpanderSink(Sink * that);

#endif
