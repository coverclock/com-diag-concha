/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/DescriptorSpanningSink.h"
#include <unistd.h>
#include <stdio.h>

ssize_t writeDescriptorSpanningSink(SpanningSink * that, const void * buffer, size_t size) {
	DescriptorSpanningSink * tp = (DescriptorSpanningSink *)that;
    int rc;

    rc = write(tp->descriptorsink.fd, buffer, size);

	return (rc > 0) ? rc : (rc == 0) ? EOF : EOR;
}

extern int writeDescriptorSink(Sink * that, char data);
extern int closeDescriptorSink(Sink * that);

static SpanningSinkVirtualTable vtable = {
    {
        writeDescriptorSink,
        closeDescriptorSink
    },
	writeDescriptorSpanningSink
};

SpanningSink * openDescriptorSpanningSink(DescriptorSpanningSink * that, int fd) {
    Sink * sink;

	sink = openDescriptorSink(&(that->descriptorsink), fd);
	that->descriptorsink.sink.vp = &(vtable.base);

    return (sink == (Sink *)0) ? (SpanningSink *)0 : (SpanningSink *)that;
}
