/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "FileDescriptorSource.h"

int readFileDescriptorSource(Source * that) {
	FileDescriptorSource * tp = (FileDescriptorSource *)that;
	int word;
	char data;
	if (tp->back != EOF) {
		word = tp->back;
		tp->back = EOF;
	} else if (read(tp->fd, &data, 1) == 1) {
		word = (unsigned)data;
	} else {
		word = EOF;
	}
	return word;
}

int pushFileDescriptorSource(Source * that, char data) {
	FileDescriptorSource * tp = (FileDescriptorSource *)that;
	return tp->back = (unsigned)data;
}

int closeFileDescriptorSource(Source * that) {
	FileDescriptorSource * tp = (FileDescriptorSource *)that;
	return close(tp->fd);
}

Source * openFileDescriptorSource(FileDescriptorSource * that, int fd) {
	that->source.read = &readFileDescriptorSource;
	that->source.push = &pushFileDescriptorSource;
	that->source.close = &closeFileDescriptorSource;
	that->fd = fd;
	that->back = EOF;
	return (Source *)that;
}
