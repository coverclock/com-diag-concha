/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "DescriptorSink.h"
#include <unistd.h>

int writeDescriptorSink(Sink * that, char data) {
	DescriptorSink * tp = (DescriptorSink *)that;
    int rc;

    rc = write(tp->fd, &data, 1);

	return  (rc == 1) ? (unsigned char)data : (rc == 0) ? EOF : EOR;
}

int closeDescriptorSink(Sink * that) {
	DescriptorSink * tp = (DescriptorSink *)that;

	return close(tp->fd);
}

static SinkVirtualTable vtable = {
	writeDescriptorSink,
	closeDescriptorSink
};

Sink * openDescriptorSink(DescriptorSink * that, int fd) {

    if ((that == (DescriptorSink *)0) || (fd < 0)) {
        return (Sink *)0;
    }

	that->sink.vp = &vtable;
	that->fd = fd;

	return (Sink *)that;
}
