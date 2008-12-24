/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "BufferSink.h"

int writeBufferSink(Sink * that, char data) {
	BufferSink * tp = (BufferSink *)that;
	return (tp->next < tp->past) ? (unsigned)(*(tp->next++) = data) : EOF;
}

int closeBufferSink(Sink * that) {
	return 0;
}

Sink * openBufferSink(BufferSink * that, char * pointer, size_t bytes) {
	that->sink.write = &writeBufferSink;
	that->sink.close = &closeBufferSink;
	that->buffer = pointer;
	that->next = pointer;
	that->past = pointer + bytes;
	return (Sink *)that;
}
