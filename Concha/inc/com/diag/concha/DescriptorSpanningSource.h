/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_DESCRIPTORSPANNINGSOURCE_
#define _H_COM_DIAG_CONCHA_DESCRIPTORSPANNINGSOURCE_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/DescriptorSource.h"
#include "com/diag/concha/SpanningSource.h"

typedef struct DescriptorSpanningSource {

    /**
     * Base class.
     */
	DescriptorSource descriptorsource;

} DescriptorSpanningSource;

/**
 * Open a Descriptor Spanning Source. The Spanning Source produces octets from a file descriptor.
 * @param that points to the Descriptor Spanning Source.
 * @param fd is an file descriptor opened for reading.
 * @return a pointer to the Descriptor Spanning Source as a Spanning Source.
 */
extern SpanningSource * openDescriptorSpanningSource(DescriptorSpanningSource * that, int fd);

#endif
