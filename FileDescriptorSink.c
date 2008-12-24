/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "FileDescriptorSink.h"

int writeFileDescriptorSink(Sink * that, char data) {
	FileDescriptorSink * tp = (FileDescriptorSink *)that;
	return (write(tp->fd, &data, 1) == 1) ? (unsigned)data : EOF;
}

int closeFileDescriptorSink(Sink * that) {
	FileDescriptorSink * tp = (FileDescriptorSink *)that;
	return close(tp->fd);
}

Sink * openFileDescriptorSink(FileDescriptorSink * that, int fd) {
	that->sink.write = &writeFileDescriptorSink;
	that->sink.close = &closeFileDescriptorSink;
	that->fd = fd;
	return (Sink *)that;
}
