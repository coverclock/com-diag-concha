/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_FLETCHER8SINK_
#define _H_COM_DIAG_CONCHA_FLETCHER8SINK_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Sink.h"
#include <stdint.h>

typedef struct Fletcher8Sink {
	Sink sink;
    Sink * to;
    uint8_t a;
    uint8_t b;
} Fletcher8Sink;

/**
 * Open an Fletcher 8-bit Sink. The Sink operates against an
 * underlying Sink while computing a Fletcher 8-bit checksum against
 * the stream of outgoing data octets.
 * @param that points to the Fletcher 8-bit Sink.
 * @param to points to the underling Sink.
 * @return a pointer to the Fletcher 8-bit Sink as a Sink.
 */
extern Sink * openFletcher8Sink(Fletcher8Sink * that, Sink * to);

/**
 * Write an octet of data to the Sink. The running value of the
 * Fletcher 8-bit checksum is computed and the octet of data is
 * written to the underlying Source.
 * @param that points to the Sink.
 * @param data is an octet to write to the Sink.
 * @return data as an integer for success, <0 otherwise.
 */
extern int writeFletcher8Sink(Sink * that, char data);

/**
 * Close the Sink. The final value of the Fletcher 8-bit checksum is
 * computed. The a and b bytes of the checksum are written to the
 * underlying Sink. The underlying Sink is closed.
 * @param that points to the Sink.
 * @return 0 for success, <0 otherwise.
 */
extern int closeFletcher8Sink(Sink * that);

#endif
