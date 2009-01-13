/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_SOURCES2SINKS_
#define _H_COM_DIAG_CONCHA_SOURCES2SINKS_

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"
#include "Sink.h"
#include <sys/types.h>
#include <stdint.h>
#include <stdio.h>

/**
 * Execute part of a unit test by reading a data from a Source,
 * and writing the data to the Sink processing multibytes at a time.
 * @param source points to the Source.
 * @param sink points to a Spanning Sink.
 * @return the number of octets transferred successfully or <0 otherwise.
 */
static int sources2sinks(Source * source, Sink * sink) {
    ssize_t total = 0;
    ssize_t reads = 0;
    ssize_t writes = 0;
    uint8_t buffer[32];

    while (1) {
        if ((reads = readsSource(source, buffer, sizeof(buffer))) == 0) {
            break;
        } else if ((writes = writesSink(sink, buffer, reads)) == 0) {
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

