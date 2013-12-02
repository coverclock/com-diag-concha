/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/StreamSink.h"

int writeStreamSink(Sink * that, char data) {
	StreamSink * tp = (StreamSink *)that;

	return fputc((unsigned char)data, tp->stream);
}

int closeStreamSink(Sink * that) {
	StreamSink * tp = (StreamSink *)that;

	return fclose(tp->stream);
}

static SinkVirtualTable vtable = {
	writeStreamSink,
	closeStreamSink
};

Sink * openStreamSink(StreamSink * that, FILE * stream) {

    if ((that == (StreamSink *)0) || (stream == (FILE *)0)) {
        return (Sink *)0;
    }

	that->sink.vp = &vtable;
	that->stream = stream;

	return (Sink *)that;
}
