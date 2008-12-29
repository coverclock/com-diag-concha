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
    Source source;
	Source * from;
    int eof;
    int x;
    int y;
    int z;
	uint8_t a;
	uint8_t b;
} Fletcher8Source;

/**
 * Open an Fletcher 8-bit Source. The Source operates against an
 * underlying Source while computing a Fletcher 8-bit checksum against
 * the stream of incoming data octets.
 * @param that points to the Fletcher 8-bit Source.
 * @param from points to the underling Source.
 * @return a pointer to the Descriptor Source as a Source.
 */
extern Source * openFletcher8Source(Fletcher8Source * that, Source * from);

/**
 * Read an octet of data from the Sink. The running value of the
 * Fletcher 8-bit checksum is computed from the octet of data that
 * was read from the underlying Source.
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
 * Close the Sink. The final value of the Fletcher 8-bit checksum is
 * computed. The a and b bytes of the checksum are written to the to
 * Sink. The to Sink is closed.
 * @param that points to the Sink.
 * @return 0 for success, <0 otherwise.
 * Close the Source. The from Source is closed.
 * @param that points to the Source.
 * @return 0 for success, <0 otherwise.
 */
extern int closeFletcher8Source(Source * that);

#endif
