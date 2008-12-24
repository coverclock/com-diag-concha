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
#include <stdio.h>

typedef struct FileSource FileSource;

struct FileSource {
	Source source;
    FILE * stream;
};

extern Source * openFileSource(FileSource * that, FILE * stream);
extern int readFileSource(Source * that);
extern int pushFileSource(Source * that, char data);
extern int closeFileSource(Source * that);

#endif
