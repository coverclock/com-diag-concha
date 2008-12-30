/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_FLETCHER8SOURCE_
#define _H_COM_DIAG_CONCHA_FLETCHER8SOURCE_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
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

/**
 * Read an octet of data from the Source. The running value of the
 * Fletcher 8-bit checksum is computed from the octet of data that
 * was read from the primary Source.
 * @param that points to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int readFletcher8Source(Source * that);

/**
 * Push an octet of data back into the Source. The octet of data is
 * decomputed from the Fletcher 8-bit checksum.
 * @param that points to the Source.
 * @param data is an octet to push back to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int pushFletcher8Source(Source * that, char data);

/**
 * Close the Source. The final value of the Fletcher 8-bit checksum is
 * computed. The a and b bytes of the checksum are compared against the
 * last two bytes from the primary Source which were not returned by
 * read. If they fail to match, the close fails. The primary Source is
 * closed.
 * @param that points to the Source.
 * @return 0 for success, <0 otherwise.
 */
extern int closeFletcher8Source(Source * that);

#endif
