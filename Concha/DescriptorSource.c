/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/DescriptorSource.h"
#include <unistd.h>

int readDescriptorSource(Source * that) {
	DescriptorSource * tp = (DescriptorSource *)that;
	char data;
    int rc;

	if (tp->pushed != EOF) {
		rc = tp->pushed;
		tp->pushed = EOF;
	} else if ((rc = read(tp->fd, &data, 1)) == 1) {
		rc = (unsigned char)data;
	} else if (rc == 0) {
		rc = EOF;
	} else {
        rc = EOR;
    }

	return rc;
}

int pushDescriptorSource(Source * that, char data) {
	DescriptorSource * tp = (DescriptorSource *)that;
    int rc;

    if (tp->pushed == EOF) {
        tp->pushed = (unsigned char)data;
        rc = tp->pushed;
    } else {
        rc = EOF;
    }

	return rc;
}

int closeDescriptorSource(Source * that) {
	DescriptorSource * tp = (DescriptorSource *)that;

	return close(tp->fd);
}

static SourceVirtualTable vtable = {
	readDescriptorSource,
	pushDescriptorSource,
	closeDescriptorSource
};

Source * openDescriptorSource(DescriptorSource * that, int fd) {

    if ((that == (DescriptorSource *)0) || (fd < 0)) {
        return (Source *)0;
    }

	that->source.vp = &vtable;
	that->fd = fd;
	that->pushed = EOF;

	return (Source *)that;
}
