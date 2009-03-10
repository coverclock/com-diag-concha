/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "copySourceToSink.h"

ssize_t copySourceToSink(Source * source, Sink * sink) {
    ssize_t total = 0;
    int data;

    while (1) {

        if ((data = readSource(source)) < 0) {
            break;
		}

        if (writeSink(sink, data) < 0) {
			(void)pushSource(source, data);
			total = -total;
			break;
    	}

        total++;

	}

    return total;
}
