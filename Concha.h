/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_CONCHA_
#define _H_COM_DIAG_CONCHA_CONCHA_

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#ifdef EOF
#undef EOF
#endif
/*
 * End Of File (EOF) indicates that a Source cannot produce or consume
 * octets now or in the future.
 */
#define EOF (-1)

#ifdef EOR
#undef EOR
#endif
/*
 * End Of File (EOF) indicates that a Source cannot produce or consume
 * octets now but may be able to do so in the future.
 */
#define EOR (-2)

#endif
