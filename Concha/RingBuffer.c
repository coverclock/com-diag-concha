/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
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
    char * consumer;

#if DEBUG
    fprintf(stderr, "%s[%d}: read size=%lu reads=%lu writes=%lu\n",
        __FILE__, __LINE__, tp->size, tp->reads, tp->writes);
#endif

    if ((tp->writes - tp->reads) == 0) {
        data = EOR;
    } else {
        consumer = tp->buffer + (tp->reads % tp->size);
        data = (unsigned char)*consumer;
        ++tp->reads;
    }

#if DEBUG
    fprintf(stderr, "%s[%d}: read size=%lu reads=%lu writes=%lu data=0x%x\n",
        __FILE__, __LINE__, tp->size, tp->reads, tp->writes, data);
#endif

	return data;
}

int pushRingBuffer(Source * that, char data) {
    RingBuffer * tp = concha_originof(RingBuffer, source, that);
    int rc;
    char * consumer;

#if DEBUG
    fprintf(stderr, "%s[%d}: push size=%lu reads=%lu writes=%lu data=0x%x\n",
        __FILE__, __LINE__, tp->size, tp->reads, tp->writes, data);
#endif

    if ((tp->writes - tp->reads) >= tp->size) {
        rc = EOR;
    } else {
        --tp->reads;
        consumer = tp->buffer + (tp->reads % tp->size);
        *consumer = data;
        rc = (unsigned char)data;
    }

#if DEBUG
    fprintf(stderr, "%s[%d}: push size=%lu reads=%lu writes=%lu rc=0x%x\n",
        __FILE__, __LINE__, tp->size, tp->reads, tp->writes, rc);
#endif

    return rc;
}

int writeRingBuffer(Sink * that, char data) {
    RingBuffer * tp = concha_originof(RingBuffer, sink, that);
    int rc;
    char * producer;

#if DEBUG
    fprintf(stderr, "%s[%d}: write size=%lu reads=%lu writes=%lu data=0x%x\n",
        __FILE__, __LINE__, tp->size, tp->reads, tp->writes, data);
#endif

    if ((tp->writes - tp->reads) >= tp->size) {
        rc = EOR;
    } else {
        producer = tp->buffer + (tp->writes % tp->size);
        *producer = data;
        ++tp->writes;
        rc = (unsigned char)data;
    }

#if DEBUG
    fprintf(stderr, "%s[%d}: write size=%lu reads=%lu writes=%lu rc=0x%x\n",
        __FILE__, __LINE__, tp->size, tp->reads, tp->writes, rc);
#endif
 
	return rc;
}

int closeRingBufferSource(Source * that) {
    return 0;
}

int closeRingBufferSink(Sink * that) {
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

    if ((that == (RingBuffer *)0) || (buffer == (void *)0)) {
        return (RingBuffer *)0;
    }

	that->source.vp = &sourcevtable;
	that->sink.vp = &sinkvtable;
    that->buffer = (char *)buffer;
    that->size = size;
    that->reads = 0;
    that->writes = 0;

    return that;
}

Source * sourceRingBuffer(RingBuffer * that) {

    if (that == (RingBuffer *)0) {
        return (Source *)0;
    }

    return &(that->source);
}

Sink * sinkRingBuffer(RingBuffer * that) {

    if (that == (RingBuffer *)0) {
        return (Sink *)0;
    }

    return &(that->sink);
}
