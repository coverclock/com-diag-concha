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
#include <stdint.h>
#include "com/diag/concha/source2sink.h"
#include "com/diag/concha/FileSource.h"
#include "com/diag/concha/FileSink.h"
#include "com/diag/concha/CompositeSource.h"

int main(int argc, char * argv[]) {
    int rc;
    FileSource filesource1;
    FileSource filesource2;
    FileSource filesource3;
    FileSink filesink;
    CompositeSource compositesource;
    CompositeSource compositesource0;
    Source * source;
    Source * source0;
    Source * source1;
    Source * source2;
    Source * source3;
    Sink * sink;

    if ((source1 = openFileSource(&filesource1, "lesser.txt")) == (Source *)0) {
        return 1;
    }

    if ((source2 = openFileSource(&filesource2, "Makefile")) == (Source *)0) {
        return 2;
    }

    if ((source3 = openFileSource(&filesource3, "README.h")) == (Source *)0) {
        return 3;
    }

    if ((source0 = openCompositeSource(&compositesource0, source2, source3)) == (Source *)0) {
        return 4;
    }

    if ((source = openCompositeSource(&compositesource, source1, source0)) == (Source *)0) {
        return 5;
    }

    if ((sink = openFileSink(&filesink, "output.txt")) == (Sink *)0) {
        return 6;
    }

    if ((rc = source2sink(source, sink)) < 0) {
        return -rc;
    }

    if (closeSource(source) == EOF) {
        return 8;
    }

    if (closeSink(sink) == EOF) {
        return 9;
    }

    return 0;
}
