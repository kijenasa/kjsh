#include "env.h"

#define _POSIX_C_SOURCE 200112L
#include <stdlib.h>
#ifdef DEBUG
#include <stdio.h>
#endif

char *get_environment_variable(char *name) {

    char *ret = getenv(name);
#ifdef DEBUG
    printf("GET ENV FOR %s: %s\n", name, ret);
#endif
    return ret;
}

int set_environment_variable(char *name, char *value) {
#ifdef DEBUG
    printf("SET ENV %s=%s\n", name, value);
#endif


    return setenv(name, value, 1);
}
