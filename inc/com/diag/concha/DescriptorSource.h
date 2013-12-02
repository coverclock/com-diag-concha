/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_DESCRIPTORSOURCE_
#define _H_COM_DIAG_CONCHA_DESCRIPTORSOURCE_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/Source.h"

typedef struct DescriptorSource {

    /**
     * Base class.
     */
	Source source;

    /**
     * File descriptor.
     */
	int fd;

    /**
     * Character pushed back into Source or EOF if none.
     */
	int pushed;

} DescriptorSource;

/**
 * Open a Descriptor Source. The Source produces octets from a file descriptor.
 * @param that points to the Descriptor Source.
 * @param fd is an file descriptor opened for reading.
 * @return a pointer to the Descriptor Source as a Source.
 */
extern Source * openDescriptorSource(DescriptorSource * that, int fd);

#endif
