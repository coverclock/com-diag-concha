/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_FLETCHER8SOURCE_
#define _H_COM_DIAG_CONCHA_FLETCHER8SOURCE_

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"
#include <stdint.h>

typedef struct Fletcher8Source {

    /**
     * Base class.
     */
    Source source;

    /**
     * Pointer to primary Source.
     */
	Source * primary;

    /**
     * State machine state.
     */
    int state;

    /**
     *  Next octet to be read by two.
     */
    int x;

    /**
     * Next octet to be read but one.
     */
    int y;

    /**
     * Next octet to be read.
     */
    int z;

    /**
     * A byte of the Fletcher 8-bit checksum.
     */
	uint8_t a;

    /**
     * B byte of the Fletcher 8-bit checksum.
     */
	uint8_t b;

} Fletcher8Source;

/**
 * Open an Fletcher 8-bit Source. The Source operates against an
 * primary Source while computing a Fletcher 8-bit checksum against
 * the stream of incoming data octets.
 * @param that points to the Fletcher 8-bit Source.
 * @param primary points to the primary Source.
 * @return a pointer to the Descriptor Source as a Source.
 */
extern Source * openFletcher8Source(Fletcher8Source * that, Source * primary);

#endif
