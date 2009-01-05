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
    RingBuffer * ring1;
    RingBuffer * ring2;
    Source * source1;
    Sink * sink1;

    if ((ring = openRingBuffer(&ringbuffer, buffer, sizeof(buffer))) == (RingBuffer *)0) {
        return 3;
    }

    if (ring != &ringbuffer) {
        return 21;
    }

    source1 = sourceRingBuffer(ring);
    if (source1 != &ringbuffer.source) {
        return 22;
    }

    sink1 = sinkRingBuffer(ring);
    if (sink1 != &ringbuffer.sink) {
        return 23;
    }

    ring1 = concha_originof(RingBuffer, source, sourceRingBuffer(ring));
    if (ring1 != ring) {
        return 24;
    }

    ring2 = concha_originof(RingBuffer, sink, sinkRingBuffer(ring));
    if (ring2 != ring) {
        return 25;
    }

    if ((ringsource = sourceRingBuffer(ring)) == (Source *)0) {
        return 4;
    }

    if ((ringsink = sinkRingBuffer(ring)) == (Sink *)0) {
        return 5;
    }

    if ((source = openFileSource(&filesource, "lesser.txt")) == (Source *)0) {
        return 1;
    }

    if ((sink = openFileSink(&filesink, "output.txt")) == (Sink *)0) {
        return 2;
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
