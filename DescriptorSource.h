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

typedef struct DescriptorSource {
	Source source;
	int fd;
	int back;
} DescriptorSource;

/**
 * Open a Descriptor Source.
 * @param that points to the Descriptor Source.
 * @param fd is an file descriptor opened for reading.
 * @return a pointer to the Descriptor Source as a Source.
 */
extern Source * openDescriptorSource(DescriptorSource * that, int fd);

/**
 * Read an octet of data from the Source.
 * @param that points to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int readDescriptorSource(Source * that);

/**
 * Push an octet of data back into the Source. It will be the next octet
 * read from the Source. Only one octet can be pushed back before being
 * re-read from the Source. The octet is not literally pushed back into
 * the underlying storage medium.
 * @param that points to the Source.
 * @param data is an octet to push back to the Source.
 * @return data as an integer for success, <0 otherwise.
 */
extern int pushDescriptorSource(Source * that, char data);

/**
 * Close the Source. This calls close(2) on the file descriptor.
 * @param that points to the Source.
 * @return 0 for success, <0 otherwise.
 */
extern int closeDescriptorSource(Source * that);

#endif
