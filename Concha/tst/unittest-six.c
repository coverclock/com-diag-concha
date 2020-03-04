/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2020 Digital Aggregates Corporation, Colorado, USA<BR>
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
#include "com/diag/concha/Fletcher8Sink.h"

int main(int argc, char * argv[]) {
    int rc;
    FileSource filesource;
    FileSink filesink;
    Fletcher8Sink f8sink;
    Source * source;
    Sink * sink;
    Sink * sink1;
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

    if ((source = openFileSource(&filesource, "lesser.txt")) == (Source *)0) {
        return 2;
    }

    if ((sink1 = openFileSink(&filesink, "output1.txt")) == (Sink *)0) {
        return 3;
    }

    if ((sink = openFletcher8Sink(&f8sink, sink1)) == (Sink *)0) {
        return 4;
    }

    if ((rc = source2sink(source, sink)) < 0) {
        return -rc;
    }

    printf("%zu: (0x%02x,0x%02x) (0x%02x,0x%02x)\n",
        count, a, b, f8sink.a, f8sink.b);

    if ((f8sink.a != a) || (f8sink.b != b)) {
        return 6;
    }

    if (closeSource(source) == EOF) {
        return 7;
    }

    if (closeSink(sink) == EOF) {
        return 8;
    }

    return 0;
}
