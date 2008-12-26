/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_FILESOURCE_
#define _H_COM_DIAG_CONCHA_FILESOURCE_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "StreamSource.h"
#include <stdio.h>

typedef StreamSource FileSource;

extern Source * openFileSource(FileSource * that, const char * path);

#endif
