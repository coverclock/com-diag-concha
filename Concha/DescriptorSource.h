/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_DESCRIPTORSOURCE_
#define _H_COM_DIAG_CONCHA_DESCRIPTORSOURCE_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"

typedef struct DescriptorSource DescriptorSource;

struct DescriptorSource {
	Source source;
	int fd;
	int back;
};

extern Source * openDescriptorSource(DescriptorSource * that, int fd);
extern int readDescriptorSource(Source * that);
extern int pushDescriptorSource(Source * that, char data);
extern int closeDescriptorSource(Source * that);

#endif
