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

#include <stdint.h>

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

/**
 * Computes the offset of a field within a structure.
 */
#define concha_offsetof(_STRUCT_, _FIELD_) \
    ((size_t)((uintptr_t)(&(((_STRUCT_ *)0)->_FIELD_)))-((uintptr_t)((_STRUCT_ *)0)))

/**
 * Computes a pointer to a structure given a pointer to one of its fields.
 */
#define concha_originof(_STRUCT_, _FIELD_, _POINTER_) \
    ((_STRUCT *)(((uintptr_t)(_POINTER_))-concha_offsetof(_STRUCT_, _FIELD_)))

#endif
