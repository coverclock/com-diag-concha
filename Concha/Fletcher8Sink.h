/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_FLETCHER8SINK_
#define _H_COM_DIAG_CONCHA_FLETCHER8SINK_

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Sink.h"
#include <stdint.h>

typedef struct Fletcher8Sink {

    /**
     * Base class.
     */
	Sink sink;

    /**
     * Pointer to primary Sink.
     */
    Sink * primary;

    /**
     * A byte of Fletcher 8-bit checksum.
     */
    uint8_t a;

    /**
     * B byte of Fletcher 8-bit checksum.
     */
    uint8_t b;

} Fletcher8Sink;

/**
 * Open an Fletcher 8-bit Sink. The Sink operates against an
 * outgoing Sink while computing a Fletcher 8-bit checksum against
 * the stream of outgoing data octets.
 * @param that points to the Fletcher 8-bit Sink.
 * @param primary points to the primary Sink.
 * @return a pointer to the Fletcher 8-bit Sink as a Sink.
 */
extern Sink * openFletcher8Sink(Fletcher8Sink * that, Sink * primary);

#endif
