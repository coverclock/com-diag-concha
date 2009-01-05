/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "DescriptorSpanningSource.h"
#include <unistd.h>

ssize_t readDescriptorSpanningSource(SpanningSource * that, void * buffer, size_t size) {
	DescriptorSpanningSource * tp = (DescriptorSpanningSource *)that;
    int rc;
    ssize_t result;

    if (size == 0) {
        result = 0;
    } else if (tp->descriptorsource.pushed != EOF) {
        *((char *)buffer) = tp->descriptorsource.pushed;
        tp->descriptorsource.pushed = EOF;
        result = 1;
    } else {
        rc = read(tp->descriptorsource.fd, buffer, size);
        result = (rc > 0) ? rc : (rc == 0) ? EOF : EOR;
    }

	return result;
}

int closeDescriptorSpanningSource(SpanningSource * that) {
	DescriptorSpanningSource * tp = (DescriptorSpanningSource *)that;

	return close(tp->descriptorsource.fd);
}

extern int readDescriptorSource(Source * that);
extern int pushDescriptorSource(Source * that, char data);
extern int closeDescriptorSource(Source * that);

static SpanningSourceVirtualTable vtable = {
    {
        readDescriptorSource,
        pushDescriptorSource,
        closeDescriptorSource
    },
	readDescriptorSpanningSource,
	closeDescriptorSpanningSource
};

SpanningSource * openDescriptorSpanningSource(DescriptorSpanningSource * that, int fd) {
    Source * source;

	source = openDescriptorSource(&(that->descriptorsource), fd);

    return (source == (Source *)0) ? (SpanningSource *)0 : (SpanningSource *)that;
}
