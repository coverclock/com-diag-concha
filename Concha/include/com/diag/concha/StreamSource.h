/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_STREAMSOURCE_
#define _H_COM_DIAG_CONCHA_STREAMSOURCE_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/Source.h"
#include <stdio.h>

typedef struct StreamSource {

    /**
     * Base class.
     */
	Source source;

    /**
     * Pointer to standard I/O stream.
     */
    FILE * stream;

} StreamSource;

/**
 * Open a Stream Source. The Source produces octets from a standard I/O stream.
 * @param that points to the Stream Source.
 * @param stream is an standard I/O stream opened for reading.
 * @return a pointer to the Stream Source as a Source.
 */
extern Source * openStreamSource(StreamSource * that, FILE * stream);

#endif
