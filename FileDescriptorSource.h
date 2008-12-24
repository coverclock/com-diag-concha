/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_FILEDESCRIPTORSOURCE_
#define _H_COM_DIAG_CONCHA_FILEDESCRIPTORSOURCE_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"
#include <unistd.h>

typedef struct FileDescriptorSource FileDescriptorSource;

struct FileDescriptorSource {
	Source source;
	int fd;
	int back;
};

extern Source * openFileDescriptorSource(FileDescriptorSource * that, int fd);
extern int readFileDescriptorSource(Source * that);
extern int pushFileDescriptorSource(Source * that, char data);
extern int closeFileDescriptorSource(Source * that);

#endif
