/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_FILEDESCRIPTORSINK_
#define _H_COM_DIAG_CONCHA_FILEDESCRIPTORSINK_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Sink.h"

typedef struct FileDescriptorSink FileDescriptorSink;

struct FileDescriptorSink {
	Sink sink;
	int fd;
};

extern Sink * openFileDescriptorSink(FileDescriptorSink * that, int fd);
extern int writeFileDescriptorSink(Sink * that, char data);
extern int closeFileDescriptorSink(Sink * that);

#endif
