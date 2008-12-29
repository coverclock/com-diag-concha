/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_STREAMSOURCE_
#define _H_COM_DIAG_CONCHA_STREAMSOURCE_

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

typedef struct StreamSource {
	Source source;
    FILE * stream;
} StreamSource;

/**
 * Open a Stream Source. The Source produces octets from a standard I/O stream.
 * @param that points to the Stream Source.
 * @param stream is an standard I/O stream opened for reading.
 * @return a pointer to the Stream Source as a Source.
 */
extern Source * openStreamSource(StreamSource * that, FILE * stream);

/**
 * Read an octet of data from the Source. An octet is read from the stream.
 * @param that points to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int readStreamSource(Source * that);

/**
 * Push an octet of data back into the Source. It will be the next octet
 * read from the Source. Only one octet can be pushed back before being
 * re-read from the Source. The octet is not literally pushed back into
 * the underlying storage medium.
 * @param that points to the Source.
 * @param data is an octet to push back to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int pushStreamSource(Source * that, char data);

/**
 * Close the Source. This calls fclose(3) on the stream.
 * @param that points to the Source.
 * @return 0 for success, <0 otherwise.
 */
extern int closeStreamSource(Source * that);

#endif
