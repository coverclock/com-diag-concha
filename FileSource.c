/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "FileSource.h"

Source * openFileSource(FileSource * that, const char * path) {
    FILE * stream;

    if ((stream = fopen(path, "r")) == (FILE *)0) {
        return (Source *)0;
    }

	return openStreamSource((StreamSource *)that, stream);
}
