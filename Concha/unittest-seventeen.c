/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "spanningsource2spanningsink.h"
#include "DescriptorSpanningSource.h"
#include "DescriptorSpanningSink.h"

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

    if ((rc = spanningsource2spanningsink(source, sink)) != EOF) {
        return 3;
    }

    if (closeSpanningSource(source) == EOF) {
        return 4;
    }

    if (closeSpanningSink(sink) == EOF) {
        return 5;
    }

    return 0;
}
