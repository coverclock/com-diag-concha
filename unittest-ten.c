/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @buffer
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
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
#include "BoundedSource.h"

int main(int argc, char * argv[]) {
    int rc;
    FileSource filesource1;
    FileSource filesource2;
    FileSink filesink;
    CompositeSource compositesource;
    BoundedSource boundedsource;
    Source * source1;
    Source * source2;
    Source * source3;
    Source * source;
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

    if ((source3 = openCompositeSource(&compositesource, source1, source2)) == (Source *)0) {
        return 4;
    }

    if ((source = openBoundedSource(&boundedsource, source3, status.st_size)) == (Source *)0) {
        return 5;
    }

    if ((sink = openFileSink(&filesink, "output.txt")) == (Sink *)0) {
        return 6;
    }

    if ((rc = source2sink(source, sink)) != EOF) {
        return 7;
    }

    if (closeSource(source) == EOF) {
        return 8;
    }

    if (closeSink(sink) == EOF) {
        return 9;
    }

    return 0;
}
