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
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "source2sink.h"
#include "BufferSource.h"
#include "BufferSink.h"
#include "StreamSink.h"
#include "ExpanderSink.h"

static char * from;
static char * to;
static char * too;

int main(int argc, char * argv[]) {
    int rc;
    BufferSource buffersource;
    BufferSink buffersink1;
    BufferSink buffersink2;
    ExpanderSink expandersink;
    Source * source;
    Sink * sink;
    Sink * sink1;
    Sink * sink2;
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

    if ((too = (char *)malloc(status.st_size)) == (char *)0) {
        perror("malloc");
        return 4;
    }

    if ((file = fopen("lesser.txt", "r")) == (FILE *)0) {
        perror("fopen");
        return 5;
    }

    if (fread(from, sizeof(char), status.st_size, file) != status.st_size) {
        return 5;
    }

    if ((source = openBufferSource(&buffersource, from, status.st_size)) == (Source *)0) {
        return 6;
    }

    if ((sink1 = openBufferSink(&buffersink1, to, status.st_size)) == (Sink *)0) {
        return 7;
    }

    if ((sink2 = openBufferSink(&buffersink2, too, status.st_size)) == (Sink *)0) {
        return 8;
    }

    if ((sink = openExpanderSink(&expandersink, sink1, sink2)) == (Sink *)0) {
        return 9;
    }

    if ((rc = source2sink(source, sink)) < 0) {
        return -rc;
    }

    if (strnlen(from, status.st_size) != strnlen(to, status.st_size)) {
        return 11;
    }

    if (strncmp(from, to, status.st_size) != 0) {
        return 12;
    }

    if (strnlen(from, status.st_size) != strnlen(too, status.st_size)) {
        return 13;
    }

    if (strncmp(from, too, status.st_size) != 0) {
        return 14;
    }

    if (closeSource(source) == EOF) {
        return 15;
    }

    if (closeSink(sink) == EOF) {
        return 16;
    }

    return 0;
}
