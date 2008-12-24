/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_SOURCE_
#define _H_COM_DIAG_CONCHA_SOURCE_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include <stdint.h>

#ifndef EOF
#define EOF (-1)
#endif

typedef struct Source Source;

struct Source {
	int (*read)(Source * that);
	int (*push)(Source * that, char data);
	int (*close)(Source * that);
};

#endif
