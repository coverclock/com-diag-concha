/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2009 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include "fletcher8.h"
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>

int main(int argc, char * argv[]) {
    uint8_t a = 0;
    uint8_t b = 0;
    size_t size = 0;

    size = fletcher8(stdin, &a, &b);

    fprintf(stderr, "%s: octets=%lu a=0x%02x b=0x%02x\n", argv[0], size, a, b);

    return 0;
}
