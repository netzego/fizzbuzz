#include <stdio.h>
#include <stdlib.h>

#include "fizzbuzz.h"

void fizzbuzz(int num, char *buf)
{
    if (num % FIZZBUZZ == 0) {
        sprintf(buf, "FIZZBUZZ");
    }

    else if (num % FIZZ == 0) {
        sprintf(buf, "FIZZ");
    }

    else if (num % BUZZ == 0) {
        sprintf(buf, "BUZZ");
    }

    else {
        sprintf(buf, "%i", num);
    }
}
