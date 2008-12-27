/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_SOURCE2SINK_
#define _H_COM_DIAG_CONCHA_SOURCE2SINK_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"
#include "Sink.h"

static int source2sink(Source * source, Sink * sink) {
    int data;
    int data2;
    while (1) {
        if ((data = readSource(source)) < 0) {
            break;
        } else if ((data = pushSource(source, (data2 = data))) < 0) {
            break;
        } else if (data != data2) {
            data = -10;
            break;
        } else if ((data = readSource(source)) < 0) {
            break;
        } else if (data != data2) {
            data = -20;
            break;
        } else if ((data = writeSink(sink, (data2 = data))) < 0) {
            break;
        } else if (data != data2) {
            data = -30;
            break;
        }
    }
    return data;
}

#endif
