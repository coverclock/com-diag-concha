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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "com/diag/concha/source2sink.h"
#include "com/diag/concha/FileSource.h"
#include "com/diag/concha/FileSink.h"
#include "com/diag/concha/BoundedSource.h"
#include "com/diag/concha/ExpanderSink.h"
#include "com/diag/concha/UnclosingSource.h"
#include "com/diag/concha/UnclosingSink.h"

int main(int argc, char * argv[]) {
    int rc;
    FileSource filesource;
    UnclosingSource unclosedsource;
    BoundedSource boundedsource;
    UnclosingSink unclosedsink;
    FileSink filesink1;
    FileSink filesink2;
    ExpanderSink expandersink;
    Source * source1;
    Source * source2;
    Source * source;
    Sink * sink1;
    Sink * sink2;
    Sink * sink3;
    Sink * sink;
    struct stat status;

    if ((rc = stat("lesser.txt", &status)) < 0) {
        perror("stat");
        return 1;
    }

    if ((source1 = openFileSource(&filesource, "lesser.txt")) == (Source *)0) {
        return 2;
    }

    if ((source2 = openUnclosingSource(&unclosedsource, source1)) == (Source *)0) {
        return 3;
    }

    if ((source = openBoundedSource(&boundedsource, source2, status.st_size / 2)) == (Source *)0) {
        return 4;
    }

    if ((sink1 = openFileSink(&filesink1, "output.txt")) == (Sink *)0) {
        return 5;
    }

    if ((sink2 = openUnclosingSink(&unclosedsink, sink1)) == (Sink *)0) {
        return 6;
    }

    if ((sink3 = openFileSink(&filesink2, "/dev/null")) == (Sink *)0) {
        return 7;
    }

    if ((sink = openExpanderSink(&expandersink, sink2, sink3)) == (Sink *)0) {
        return 8;
    }

    if ((rc = source2sink(source, sink)) < 0) {
        return -rc;
    }

    if (closeSource(source) == EOF) {
        return 10;
    }

    if (closeSink(sink) == EOF) {
        return 11;
    }

    if ((rc = source2sink(source1, sink1)) < 0) {
        return -rc;
    }

    if (closeSource(source1) == EOF) {
        return 13;
    }

    if (closeSink(sink1) == EOF) {
        return 14;
    }

    return 0;
}
