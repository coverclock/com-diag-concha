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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "source2sink.h"
#include "FileSource.h"
#include "FileSink.h"
#include "CompositeSource.h"
#include "BoundedSink.h"

int main(int argc, char * argv[]) {
    int rc;
    FileSource filesource1;
    FileSource filesource2;
    FileSink filesink;
    CompositeSource compositesource;
    BoundedSink boundedsink;
    Source * source1;
    Source * source2;
    Source * source;
    Sink * sink1;
    Sink * sink;
    struct stat status;

    if ((rc = stat("lesser.txt", &status)) < 0) {
        perror("stat");
        return 1;
    }

    if ((source1 = openFileSource(&filesource1, "lesser.txt")) == (Source *)0) {
        return 2;
    }

    if ((source2 = openFileSource(&filesource2, "README.h")) == (Source *)0) {
        return 3;
    }

    if ((source = openCompositeSource(&compositesource, source1, source2)) == (Source *)0) {
        return 4;
    }

    if ((sink1 = openFileSink(&filesink, "output.txt")) == (Sink *)0) {
        return 5;
    }

    if ((sink = openBoundedSink(&boundedsink, sink1, status.st_size)) == (Sink *)0) {
        return 6;
    }

    if ((rc = source2sink(source, sink)) != -105) {
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
