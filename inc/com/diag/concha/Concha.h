/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_CONCHA_
#define _H_COM_DIAG_CONCHA_CONCHA_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include <stdio.h>

#ifndef EOF
/**
 * End Of File (EOF) indicates that a Source cannot produce or consume
 * octets now or in the future.
 */
#define EOF (-1)
#endif

#ifdef EOR
#undef EOR
#endif
/**
 * End Of Record (EOR) indicates that a Source cannot produce or consume
 * octets now but may be able to do so in the future. For example, in a
 * socket-based Source, there may no data currently available at this
 * end of the socket.
 */
#define EOR (-2)

#endif
