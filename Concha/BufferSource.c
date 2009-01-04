/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "BufferSource.h"

int readBufferSource(Source * that) {
	BufferSource * tp = (BufferSource *)that;

	return (tp->next < tp->past) ? (unsigned char)*(tp->next++) : EOF;
}

int pushBufferSource(Source * that, char data) {
	BufferSource * tp = (BufferSource *)that;

	return (tp->next > tp->buffer) ? (unsigned char)(*(--tp->next) = data) : EOF;
}

int closeBufferSource(Source * that) {
	return 0;
}

static SourceVirtualTable vtable = {
	readBufferSource,
	pushBufferSource,
	closeBufferSource
};

Source * openBufferSource(BufferSource * that, void * buffer, size_t size) {

    if ((that == (BufferSource *)0) || (buffer == (void *)0)) {
        return (Source *)0;
    }

	that->source.vp = &vtable;
	that->buffer = (char *)buffer;
	that->next = that->buffer;
	that->past = that->buffer + size;

	return (Source *)that;
}
