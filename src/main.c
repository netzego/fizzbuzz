#include <stdio.h>
#include <stdlib.h>

#include "fizzbuzz.h"

#define MIN -15
#define MAX 15

int main(void)
{
    char res[BUFSIZE];

    for (int i = MIN; i <= MAX; i++) {
        fizzbuzz(i, res);
        printf("%s\n", res);
    }

    return EXIT_SUCCESS;
}
