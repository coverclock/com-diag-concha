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
#include "RingBuffer.h"
#include "helpers.h"

int main(int argc, char * argv[]) {
    int rc;
    FileSource filesource;
    FileSink filesink;
    RingBuffer ringbuffer;
    Source * source;
    Sink * sink;
    Source * ringsource;
    Sink * ringsink;
    RingBuffer * ring;
    char buffer[32];
    int eof = 0;
    int data;

    printf("%p %p %p %lu %lu %p %p\n",
        &ringbuffer,
        &ringbuffer.source,
        &ringbuffer.sink,
        concha_offsetof(RingBuffer, source),
        concha_offsetof(RingBuffer, sink),
        concha_originof(RingBuffer, source, &ringbuffer.source),
        concha_originof(RingBuffer, sink, &ringbuffer.sink));

    if ((source = openFileSource(&filesource, "lesser.txt")) == (Source *)0) {
        return 1;
    }

    if ((sink = openFileSink(&filesink, "output.txt")) == (Sink *)0) {
        return 2;
    }

    if ((ring = openRingBuffer(&ringbuffer, buffer, sizeof(buffer))) == (RingBuffer *)0) {
        return 3;
    }

    if ((ringsource = sourceRingBuffer(ring)) == (Source *)0) {
        return 4;
    }

    if ((ringsink = sinkRingBuffer(ring)) == (Sink *)0) {
        return 5;
    }

    while (!eof) {

        while (!eof) {
	        if ((data = readSource(source)) == EOF) {
	            eof = !0;
	        } else if ((rc = writeSink(ringsink, data)) == EOF) {
	            return 6;
	        } else if (rc != EOR) {
                /* Do nothing. */
	        } else if ((rc = pushSource(source, data)) == EOF) {
	            return 7;
	        } else {
                break;
            }
        }

        while (1) {
            if ((data = readSource(ringsource)) == EOF) {
                return 8;
            }  else if (data == EOR) {
                break;
            } else if ((rc == writeSink(sink, data)) == EOF) {
                return 8;
            } else {
                /* Do nothing. */
            }
        }

    }

    if (closeSource(ringsource) == EOF) {
        return 9;
    }

    if (closeSink(ringsink) == EOF) {
        return 10;
    }

    if (closeSource(source) == EOF) {
        return 11;
    }

    if (closeSink(sink) == EOF) {
        return 12;
    }

    return 0;
}
