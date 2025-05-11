#include "builtins/clear.h"

#include <stdio.h>
#include "config.h"

int kj_clear(int argc, char *argv[]) {
    (void) argc;
    (void) argv;

    puts(CLEAR_SCREEN);
    return 0;
}
