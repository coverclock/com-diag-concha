/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "DescriptorSink.h"
#include <unistd.h>

int writeDescriptorSink(Sink * that, char data) {
	DescriptorSink * tp = (DescriptorSink *)that;
	return (write(tp->fd, &data, 1) == 1) ? (unsigned)data : EOF;
}

int closeDescriptorSink(Sink * that) {
	DescriptorSink * tp = (DescriptorSink *)that;
	return close(tp->fd);
}

Sink * openDescriptorSink(DescriptorSink * that, int fd) {
	that->sink.write = &writeDescriptorSink;
	that->sink.close = &closeDescriptorSink;
	that->fd = fd;
	return (Sink *)that;
}
