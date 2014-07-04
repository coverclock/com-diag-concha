/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "com/diag/concha/FileSource.h"

Source * openFileSource(FileSource * that, const char * path) {
    FILE * stream;

    if ((that == (FileSource *)0) || ((stream = fopen(path, "r")) == (FILE *)0)) {
        return (Source *)0;
    }

	return openStreamSource((StreamSource *)that, stream);
}
