/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "DescriptorSource.h"
#include <unistd.h>

int readDescriptorSource(Source * that) {
	DescriptorSource * tp = (DescriptorSource *)that;
	int word;
	char data;

	if (tp->back != EOF) {
		word = tp->back;
		tp->back = EOF;
	} else if (read(tp->fd, &data, 1) == 1) {
		word = (unsigned char)data;
	} else {
		word = EOF;
	}

	return word;
}

int pushDescriptorSource(Source * that, char data) {
	DescriptorSource * tp = (DescriptorSource *)that;

	return tp->back = (unsigned char)data;
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

	that->source.vp = &vtable;
	that->fd = fd;
	that->back = EOF;

	return (Source *)that;
}
