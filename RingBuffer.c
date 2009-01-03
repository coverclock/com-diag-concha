/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "RingBuffer.h"
#include "helpers.h"
#include <stdint.h>

int readRingBuffer(Source * that) {
    RingBuffer * tp = concha_originof(RingBuffer, source, that);
    int data;

    if (tp->consumer == (char *)0) {
        data = EOF;
    } else if (tp->consumer == tp->producer) {
        data = EOR;
    } else {
        data = (unsigned char)*(tp->consumer++);
        if (tp->consumer >= tp->past) { tp->consumer = tp->buffer; }
    }

	return data;
}

int pushRingBuffer(Source * that, char data) {
    RingBuffer * tp = concha_originof(RingBuffer, source, that);
    char * prior;
    int rc;

    if (tp->consumer == (char *)0) {
        rc = EOF;
    } else {
        prior = tp->consumer - 1;
        if (prior < tp->buffer) { prior = tp->past - 1; }
        if (prior == tp->producer) {
            rc = EOR;
        } else {
            tp->consumer = prior;
            *tp->consumer = data;
            rc = (unsigned char)data;
        }
    }

    return rc;
}

int writeRingBuffer(Sink * that, char data) {
    RingBuffer * tp = concha_originof(RingBuffer, source, that);
    char * next;
    int rc;

    if (tp->producer == (char *)0) {
        rc = EOF;
    } else {
        next = tp->producer + 1;
        if (next >= tp->past) { next = tp->buffer; }
        if (next == tp->consumer) {
            rc = EOR;
        } else {
            tp->producer = next;
            *tp->producer = data;
            rc = (unsigned char)data;
        }
    }
        
	return rc;
}

int closeRingBufferSource(Source * that) {
    RingBuffer * tp = concha_originof(RingBuffer, source, that);

    tp->consumer = (char *)0;

    return 0;
}

int closeRingBufferSink(Sink * that) {
    RingBuffer * tp = concha_originof(RingBuffer, sink, that);

    tp->producer = (char *)0;

    return 0;
}

static SourceVirtualTable sourcevtable = {
	readRingBuffer,
	pushRingBuffer,
	closeRingBufferSource
};

static SinkVirtualTable sinkvtable = {
	writeRingBuffer,
	closeRingBufferSink
};

RingBuffer * openRingBuffer(RingBuffer * that, void * buffer, size_t size) {

	that->source.vp = &sourcevtable;
	that->sink.vp = &sinkvtable;
    that->buffer = (char *)buffer;
    that->past = that->buffer + size;
    that->producer = that->buffer;
    that->consumer = that->buffer;

    return that;
}

Source * sourceRingBuffer(RingBuffer * that) {
    return &(that->source);
}

Sink * sinkRingBuffer(RingBuffer * that) {
    return &(that->sink);
}
