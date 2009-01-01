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
#include "BufferSource.h"
#include "BufferSink.h"

static char * from;
static char * to;

int main(int argc, char * argv[]) {
    int rc;
    BufferSource buffersource;
    BufferSink buffersink;
    Source * source;
    Sink * sink;
    struct stat status;
    FILE * file;

    if ((rc = stat("lesser.txt", &status)) < 0) {
        perror("stat");
        return 1;
    }

    if ((from = (char *)malloc(status.st_size)) == (char *)0) {
        perror("malloc");
        return 2;
    }

    if ((to = (char *)malloc(status.st_size)) == (char *)0) {
        perror("malloc");
        return 3;
    }

    if ((file = fopen("lesser.txt", "r")) == (FILE *)0) {
        perror("fopen");
        return 5;
    }

    if (fread(from, sizeof(char), status.st_size, file) != status.st_size) {
        return 4;
    }

    if ((source = openBufferSource(&buffersource, from, status.st_size)) == (Source *)0) {
        return 5;
    }

    if ((sink = openBufferSink(&buffersink, to, status.st_size)) == (Sink *)0) {
        return 6;
    }

    if ((rc = source2sink(source, sink)) != EOF) {
        return 7;
    }

    if (strnlen(from, status.st_size) != strnlen(to, status.st_size)) {
        return 8;
    }

    if (strncmp(from, to, status.st_size) != 0) {
        return 9;
    }

    if (closeSource(source) == EOF) {
        return 10;
    }

    if (closeSink(sink) == EOF) {
        return 11;
    }

    return 0;
}
