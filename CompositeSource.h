/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_COMPOSITESOURCE_
#define _H_COM_DIAG_CONCHA_COMPOSITESOURCE_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"

typedef struct CompositeSource {
	Source source;
	Source * primary;
	Source * secondary;
} CompositeSource;

extern Source * openCompositeSource(CompositeSource * that, Source * primary, Source * secondary);
extern int readCompositeSource(Source * that);
extern int pushCompositeSource(Source * that, char data);
extern int closeCompositeSource(Source * that);

#endif
