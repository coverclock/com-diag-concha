/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_EXPANDERSINK_
#define _H_COM_DIAG_CONCHA_EXPANDERSINK_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/Sink.h"
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

#endif
