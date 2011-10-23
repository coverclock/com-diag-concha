/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_HELPERS_
#define _H_COM_DIAG_CONCHA_HELPERS_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include <stdint.h>
#include <sys/types.h>

/**
 * Computes the offset of a field within a structure.
 */
#define concha_offsetof(_STRUCT_, _FIELD_) \
    ((size_t)((uintptr_t)(&(((_STRUCT_ *)0)->_FIELD_)))-((uintptr_t)((_STRUCT_ *)0)))

/**
 * Computes a pointer to a structure given a pointer to one of its fields.
 */
#define concha_originof(_STRUCT_, _FIELD_, _POINTER_) \
    ((_STRUCT_ *)(((uintptr_t)(_POINTER_))-concha_offsetof(_STRUCT_, _FIELD_)))

#endif
