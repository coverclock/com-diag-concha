/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_DESCRIPTORSINK_
#define _H_COM_DIAG_CONCHA_DESCRIPTORSINK_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/Sink.h"

typedef struct DescriptorSink {

    /**
     * Base class.
     */
	Sink sink;

    /**
     * File descriptor.
     */
	int fd;

} DescriptorSink;

/**
 * Open a Descriptor Sink. The Sink consumes octets from a file descriptor.
 * @param that points to the Descriptor Sink.
 * @param fd is an file descriptor opened for writing.
 * @return a pointer to the Descriptor Sink as a Sink.
 */
extern Sink * openDescriptorSink(DescriptorSink * that, int fd);

#endif
