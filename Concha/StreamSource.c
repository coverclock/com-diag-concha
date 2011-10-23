/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/StreamSource.h"

int readStreamSource(Source * that) {
	StreamSource * tp = (StreamSource *)that;

    return fgetc(tp->stream);
}

int pushStreamSource(Source * that, char data) {
	StreamSource * tp = (StreamSource *)that;

	return ungetc((unsigned char)data, tp->stream);
}

int closeStreamSource(Source * that) {
	StreamSource * tp = (StreamSource *)that;

	return fclose(tp->stream);
}

static SourceVirtualTable vtable = {
	readStreamSource,
	pushStreamSource,
	closeStreamSource
};

Source * openStreamSource(StreamSource * that, FILE * stream) {

    if ((that == (StreamSource *)0) || (stream == (FILE *)0)) {
        return (Source *)0;
    }

	that->source.vp = &vtable;
	that->stream = stream;

	return (Source *)that;
}
