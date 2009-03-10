/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_COPY_SOURCE_TO_SINK_
#define _H_COM_DIAG_CONCHA_COPY_SOURCE_TO_SINK_

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Source.h"
#include "Sink.h"
#include <sys/types.h>

/**
 * Copy a source to a sink. If the sink fills before the source is empty,
 * all remaining data is left in the source.
 * @param source points to the Source.
 * @param sink points to a Sink.
 * @return the number of octets transferred successfully, as a negative
 * number if an error occurred before the source was empty.
 */
ssize_t copySourceToSink(Source * source, Sink * sink);

#endif
