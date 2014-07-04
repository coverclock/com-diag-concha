/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include <stdio.h>
#include "com/diag/concha/NullSource.h"
#include "com/diag/concha/NullSink.h"

int main(int argc, char * argv[]) {
    int rc;
    NullSource nullsource;
    NullSink nullsink;
    Source * source;
    Sink * sink;

    if ((source = openNullSource(&nullsource)) == (Source *)0) {
        return 1;
    }

    if ((sink = openNullSink(&nullsink)) == (Sink *)0) {
        return 2;
    }

    if (readSource(source) != EOF) {
        return 3;
    }

    if (pushSource(source, ' ') != EOF) {
        return 4;
    }

    if (writeSink(sink, ' ') != ' ') {
        return 5;
    }

    if (closeSource(source) == EOF) {
        return 6;
    }

    if (closeSink(sink) == EOF) {
        return 7;
    }

    return 0;
}
