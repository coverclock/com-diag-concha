/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "FileSink.h"

int writeFileSink(Sink * that, char data) {
	FileSink * tp = (FileSink *)that;
	return fputc((unsigned char)data, tp->stream);
}

int closeFileSink(Sink * that) {
	FileSink * tp = (FileSink *)that;
	return fclose(tp->stream);
}

Sink * openFileSink(FileSink * that, FILE * stream) {
	that->sink.write = &writeFileSink;
	that->sink.close = &closeFileSink;
	that->stream = stream;
	return (Sink *)that;
}
