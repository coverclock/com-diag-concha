/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_FILESINK_
#define _H_COM_DIAG_CONCHA_FILESINK_

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "StreamSink.h"
#include <stdio.h>

typedef StreamSink FileSink;

/**
 * Open a File Sink. The Sink is identical to a Stream Sink with a stream
 * resulting from opening the specified path for writing.
 * @param that points to the File Sink.
 * @param path names a file to be opened for writing.
 * @return a pointer to the File Sink as a Sink.
 */
extern Sink * openFileSink(FileSink * that, const char * path);

#endif
