#include "hash.h"

#ifdef DEBUG
#include <stdio.h>
#endif

int hash_string(const char *str) {
    int sum = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] != '\n')
            sum += (int)str[i] * (i + 1);
    }
#ifdef DEBUG
    printf("Hash for \"%s\": %d\n", str, sum);
#endif
    return sum;
}
