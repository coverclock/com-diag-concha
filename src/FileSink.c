/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/FileSink.h"

Sink * openFileSink(FileSink * that, const char * path) {
    FILE * stream;

    if ((that == (FileSink *)0) || ((stream = fopen(path, "w")) == (FILE *)0)) {
        return (Sink *)0;
    }

	return openStreamSink((StreamSink *)that, stream);
}
