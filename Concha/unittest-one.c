/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include <stdio.h>
#include "source2sink.h"
#include "StreamSource.h"
#include "StreamSink.h"

int main(int argc, char * argv[]) {
    int rc;
    StreamSource streamsource;
    StreamSink streamsink;
    Source * source;
    Sink * sink;

    if ((source = openStreamSource(&streamsource, stdin)) == (Source *)0) {
        return 1;
    }

    if ((sink = openStreamSink(&streamsink, stdout)) == (Sink *)0) {
        return 2;
    }

    if ((rc = source2sink(source, sink)) < 0) {
        return -rc;
    }

    if (closeSource(source) == EOF) {
        return 4;
    }

    if (closeSink(sink) == EOF) {
        return 5;
    }

    return 0;
}
