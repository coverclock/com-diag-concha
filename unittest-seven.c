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
#include "com/diag/concha/fletcher8.h"
#include "com/diag/concha/FileSource.h"
#include "com/diag/concha/FileSink.h"
#include "com/diag/concha/Fletcher8Source.h"

int main(int argc, char * argv[]) {
    int rc;
    FileSource filesource;
    FileSink filesink;
    Fletcher8Source f8source;
    Source * source;
    Source * source1;
    Sink * sink;
    uint8_t a;
    uint8_t b;
    FILE * file;
    size_t count;

    if ((file = fopen("lesser.txt", "r")) == (FILE *)0) {
        perror("fopen");
        return 1;
    }

    count = fletcher8(file, &a, &b);

    if (fclose(file) == EOF) {
        perror("fclose");
        return 2;
    }

    if ((source1 = openFileSource(&filesource, "output1.txt")) == (Source *)0) {
        return 1;
    }

    if ((source = openFletcher8Source(&f8source, source1)) == (Source *)0) {
        return 3;
    }

    if ((sink = openFileSink(&filesink, "output.txt")) == (Sink *)0) {
        return 2;
    }

    if ((rc = source2sink(source, sink)) < 0) {
        return -rc;
    }

    printf("%u: (0x%02x,0x%02x) (0x%02x,0x%02x) (0x%02x,0x%02x)\n",
        count, a, b, f8source.a, f8source.b, f8source.y, f8source.z);

    if ((f8source.a != a) || (f8source.b != b)) {
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
