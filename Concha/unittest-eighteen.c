/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/sources2sinks.h"
#include "com/diag/concha/DescriptorSource.h"
#include "com/diag/concha/DescriptorSink.h"

int main(int argc, char * argv[]) {
    int rc;
    DescriptorSource fdsource;
    DescriptorSink fdsink;
    Source * source;
    Sink * sink;

    if ((source = openDescriptorSource(&fdsource, 0)) == (Source *)0) {
        return 1;
    }

    if ((sink = openDescriptorSink(&fdsink, 1)) == (Sink *)0) {
        return 2;
    }

    if ((rc = sources2sinks(source, sink)) < 0) {
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


