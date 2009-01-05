/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "DescriptorSpanningSink.h"
#include <unistd.h>

ssize_t writeDescriptorSpanningSink(SpanningSink * that, const void * buffer, size_t size) {
	DescriptorSpanningSink * tp = (DescriptorSpanningSink *)that;
    int rc;
    
    rc = write(tp->descriptorsink.fd, buffer, size);

	return (rc > 0) ? rc : (rc == 0) ? EOF : EOR;
}

int closeDescriptorSpanningSink(SpanningSink * that) {
	DescriptorSpanningSink * tp = (DescriptorSpanningSink *)that;

	return close(tp->descriptorsink.fd);
}

extern int writeDescriptorSink(Sink * that, char data);
extern int closeDescriptorSink(Sink * that);

static SpanningSinkVirtualTable vtable = {
    {
        writeDescriptorSink,
        closeDescriptorSink
    },
	writeDescriptorSpanningSink,
	closeDescriptorSpanningSink
};

SpanningSink * openDescriptorSpanningSink(DescriptorSpanningSink * that, int fd) {
    Sink * sink;

	sink = openDescriptorSink(&(that->descriptorsink), fd);

    return (sink == (Sink *)0) ? (SpanningSink *)0 : (SpanningSink *)that;
}
