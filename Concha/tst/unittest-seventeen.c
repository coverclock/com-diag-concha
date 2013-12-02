/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/spanningsource2spanningsink.h"
#include "com/diag/concha/DescriptorSpanningSource.h"
#include "com/diag/concha/DescriptorSpanningSink.h"
#include <errno.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
    int rc;
    DescriptorSpanningSource spanningsource;
    DescriptorSpanningSink spanningsink;
    SpanningSource * source;
    SpanningSink * sink;

    if ((source = openDescriptorSpanningSource(&spanningsource, 0)) == (SpanningSource *)0) {
        return 1;
    }

    if ((sink = openDescriptorSpanningSink(&spanningsink, 1)) == (SpanningSink *)0) {
        return 2;
    }

    if ((rc = spanningsource2spanningsink(source, sink)) < 0) {
        return -rc;
    }

    if (closeSpanningSource(source) == EOF) {
        return 4;
    }

    if (closeSpanningSink(sink) == EOF) {
        return 5;
    }

    return 0;
}
