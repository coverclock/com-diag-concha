/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "StreamSource.h"
#include "StreamSink.h"
#include "copySourceToSink.h"

int main(int argc, char * argv[]) {
    int xc = 0;
    StreamSource streamsource;
    StreamSink streamsink;
    Source * source;
    Sink * sink;

    do {

	    if ((source = openStreamSource(&streamsource, stdin)) == NULL) {
	        xc = 1;
            break;
	    }
	
	    if ((sink = openStreamSink(&streamsink, stdout)) == NULL) {
	        xc = 2;
            break;
	    }
	
	    if (copySourceToSink(source, sink) < 0) {
	        xc = 3;
	    }
	
	} while (0);
	
	if ((source != NULL) && (closeSource(source) == EOF)) {
        xc = 4;
	}
	
	if ((sink != NULL) && (closeSink(sink) == EOF)) {
        xc = 5;
	}

    return xc;
}
