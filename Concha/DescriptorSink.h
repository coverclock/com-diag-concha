/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_DESCRIPTORSINK_
#define _H_COM_DIAG_CONCHA_DESCRIPTORSINK_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "Sink.h"

typedef struct DescriptorSink {
	Sink sink;
	int fd;
} DescriptorSink;

/**
 * Open a Descriptor Sink.
 * @param that points to the Descriptor Sink.
 * @param fd is an file descriptor opened for writing.
 * @return a pointer to the Descriptor Sink as a Sink.
 */
extern Sink * openDescriptorSink(DescriptorSink * that, int fd);

/**
 * Write an octet of data to the Sink.
 * @param that points to the Sink.
 * @param data is an octet to write into the Sink.
 * @return data as an integer for success, <0 otherwise.
 */
extern int writeDescriptorSink(Sink * that, char data);

/**
 * Close the Sink. This calls close(2) on the file descriptor.
 * @param that points to the Sink.
 * @return 0 for success, <0 otherwise.
 */
extern int closeDescriptorSink(Sink * that);

#endif
