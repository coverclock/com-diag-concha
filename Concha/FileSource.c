/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "FileSource.h"

int readFileSource(Source * that) {
	FileSource * tp = (FileSource *)that;

    return fgetc(tp->stream);
}

int pushFileSource(Source * that, char data) {
	FileSource * tp = (FileSource *)that;
	return ungetc((unsigned char)data, tp->stream);
}

int closeFileSource(Source * that) {
	FileSource * tp = (FileSource *)that;
	return fclose(tp->stream);
}

Source * openFileSource(FileSource * that, FILE * stream) {
	that->source.read = &readFileSource;
	that->source.push = &pushFileSource;
	that->source.close = &closeFileSource;
	that->stream = stream;
	return (Source *)that;
}
