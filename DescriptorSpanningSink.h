/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_DESCRIPTORSPANNINGSINK_
#define _H_COM_DIAG_CONCHA_DESCRIPTORSPANNINGSINK_

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "DescriptorSink.h"
#include "SpanningSink.h"

typedef struct DescriptorSpanningSink {

    /**
     * Base class.
     */
	DescriptorSink descriptorsink;

} DescriptorSpanningSink;

/**
 * Open a Descriptor SpanningSink. The SpanningSink consumes octets from a
 * file descriptor.
 * @param that points to the Descriptor SpanningSink.
 * @param fd is an file descriptor opened for writing.
 * @return a pointer to the Descriptor SpanningSink as a SpanningSink.
 */
extern SpanningSink * openDescriptorSpanningSink(DescriptorSpanningSink * that, int fd);

#endif
