/* vi: set ts=4 expandtab shiftwidth=4: */
#ifndef _H_COM_DIAG_CONCHA_FLETCHER8_
#define _H_COM_DIAG_CONCHA_FLETCHER8_

/**
 * @file
 *
 * Copyright 2009-2011 Digital Aggregates Corporation, Colorado, USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include <stdio.h>
#include <stdint.h>

/**
 * Compute the Fletcher 8-bit checksum as part of a unit test.
 * @param file points to a standard I/O stream open for input.
 * @param ap points to the A variable.
 * @param bp points to the B variable.
 * @return the number of octets processed.
 */
static size_t fletcher8(FILE * file, uint8_t * ap, uint8_t * bp) {
    uint8_t a = 0;
    uint8_t b = 0;
    size_t n = 0;
    int data;
    while ((data = getc(file)) != EOF) {
        a += (uint8_t)data;
        b += a;
        ++n;
    }
    *ap = a;
    *bp = b;
    return n;
}

#endif
