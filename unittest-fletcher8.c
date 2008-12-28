/* vi: set ts=4 expandtab shiftwidth=4: */

/**
 * @file
 *
 * Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA<BR>
 * Licensed under the terms in README.h<BR>
 * Chip Overclock <coverclock@diag.com><BR>
 * http://www.diag.com/navigation/downloads/Concha.html<BR>
 */

#include <stdio.h>
#include <stdint.h>

int main(int argc, char * argv[]) {
    int data;
    uint8_t a = 0;
    uint8_t b = 0;
    while ((data = getc(stdin)) != EOF) {
        a += (uint8_t)data;
        b += a;
        putc(data, stdout);
    }
    fprintf(stderr, "%s: a=0x%02x b=0x%02x\n", argv[0], a, b);
    return 0;
}
