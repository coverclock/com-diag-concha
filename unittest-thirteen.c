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
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "source2sink.h"
#include "BufferSource.h"
#include "BufferSink.h"
#include "ClosingSource.h"
#include "ClosingSink.h"

int main(int argc, char * argv[]) {
    int rc;
    BufferSink buffersink;
    ClosingSink closingsink;
    BufferSource buffersource;
    ClosingSource closingsource;
    Source * source1;
    Source * source;
    Sink * sink1;
    Sink * sink;
    char buffer[4];

    if ((sink1 = openBufferSink(&buffersink, buffer, sizeof(buffer))) == (Sink *)0) {
        return 1;
    }

    if ((sink = openClosingSink(&closingsink, sink1)) == (Sink *)0) {
        return 2;
    }

    if (writeSink(sink, 0xc0) != 0xc0) {
        return 3;
    }

    if (writeSink(sink, 0x01) != 0x01) {
        return 4;
    }

    if (writeSink(sink, 0xc0) != 0xc0) {
        return 5;
    }

    if (writeSink(sink, 0xed) != 0xed) {
        return 6;
    }

    if (writeSink(sink, 0xff) != EOF) {
        return 7;
    }

    if (closeSink(sink1) != 0) {
        return 8;
    }

    if ((sink1 = openBufferSink(&buffersink, buffer, sizeof(buffer))) == (Sink *)0) {
        return 9;
    }

    if (writeSink(sink, 0xff) != EOF) {
        return 10;
    }

    if (closeSink(sink) != 0) {
        return 11;
    }

    if (closeSink(sink) != EOF) {
        return 12;
    }

    if ((source1 = openBufferSource(&buffersource, buffer, sizeof(buffer))) == (Source *)0) {
        return 13;
    }

    if ((source = openClosingSource(&closingsource, source1)) == (Source *)0) {
        return 14;
    }

    if (readSource(source) != 0xc0) {
        return 15;
    }

    if (readSource(source) != 0x01) {
        return 16;
    }

    if (readSource(source) != 0xc0) {
        return 17;
    }

    if (readSource(source) != 0xed) {
        return 18;
    }

    if (readSource(source) != EOF) {
        return 19;
    }

    if (closeSource(source1) != 0) {
        return 20;
    }

    if ((source1 = openBufferSource(&buffersource, buffer, sizeof(buffer))) == (Source *)0) {
        return 21;
    }

    if (readSource(source) != EOF) {
        return 22;
    }

    if (closeSource(source) != 0) {
        return 23;
    }

    if (closeSource(source) != EOF) {
        return 24;
    }

    return 0;
}
