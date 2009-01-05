/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_SOURCE2SINK_
#define _H_COM_DIAG_CONCHA_SOURCE2SINK_

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

/**
 * Execute part of a unit test by reading a data from a Source, pushing
 * the data back into the Source, re-reading the data from the Source,
 * and writing the data to the Sink.
 * @param source points to the Source.
 * @param sink points to a Sink.
 * @return the number of octets transferred successfully or <0 otherwise.
 */
static ssize_t source2sink(Source * source, Sink * sink) {
    ssize_t total = 0;
    int data;
    int data2;

    while (1) {
        if ((data = readSource(source)) < 0) {
            break;
        } else if ((data = pushSource(source, (data2 = data))) < 0) {
            total = -101;
            break;
        } else if (data != data2) {
            total = -102;
            break;
        } else if ((data = readSource(source)) < 0) {
            total = -103;
            break;
        } else if (data != data2) {
            total = -104;
            break;
        } else if ((data = writeSink(sink, (data2 = data))) < 0) {
            total = -105;
            break;
        } else if (data != data2) {
            total = -106;
            break;
        } else {
            ++total;
        }
    }

    return total;
}

#endif
