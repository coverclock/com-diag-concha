/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "StreamSource.h"

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

Source * openStreamSource(StreamSource * that, FILE * stream) {
	that->source.read = &readStreamSource;
	that->source.push = &pushStreamSource;
	that->source.close = &closeStreamSource;
	that->stream = stream;
	return (Source *)that;
}
