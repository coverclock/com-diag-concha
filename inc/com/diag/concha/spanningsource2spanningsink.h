/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_SPANNINGSOURCE2SPANNINGSINK_
#define _H_COM_DIAG_CONCHA_SPANNINGSOURCE2SPANNINGSINK_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/SpanningSource.h"
#include "com/diag/concha/SpanningSink.h"
#include <sys/types.h>
#include <stdint.h>
#include <stdio.h>

/**
 * Execute part of a unit test by reading a data from a Spanning Source,
 * and writing the data to the Spanning Sink.
 * @param source points to the Spanning Source.
 * @param sink points to a Spanning Sink.
 * @return the number of octets transferred successfully or <0 otherwise.
 */
static int spanningsource2spanningsink(SpanningSource * source, SpanningSink * sink) {
    ssize_t total = 0;
    ssize_t reads = 0;
    ssize_t writes = 0;
    uint8_t buffer[32];

    while (1) {
        if ((reads = readSpanningSource(source, buffer, sizeof(buffer))) < 0) {
            break;
        } else if (reads == 0) {
            total = -111;
            break;
        } else if ((writes = writeSpanningSink(sink, buffer, reads)) < 0) {
            total = -112;
            break;
        } else if (writes != reads) {
            total = -113;
            break;
        } else {
            total += writes;
        }
    }

    return total;
}

#endif
