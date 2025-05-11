#include "builtins/exit.h"

#include <stdlib.h>

int kj_exit(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    exit(0);
}
