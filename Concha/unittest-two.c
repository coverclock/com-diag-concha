/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "source2sink.h"
#include "DescriptorSource.h"
#include "DescriptorSink.h"

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
    if ((rc = source2sink(source, sink)) != EOF) {
        return 3;
    }
    return 0;
}

