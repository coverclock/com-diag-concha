/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/source2sink.h"
#include "com/diag/concha/FileSource.h"
#include "com/diag/concha/FileSink.h"

int main(int argc, char * argv[]) {
    int rc;
    FileSource filesource;
    FileSink filesink;
    Source * source;
    Sink * sink;
    if ((source = openFileSource(&filesource, "lesser.txt")) == (Source *)0) {
        return 1;
    }
    if ((sink = openFileSink(&filesink, "output.txt")) == (Sink *)0) {
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
