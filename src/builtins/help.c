#include "builtins/help.h"

#include "config.h"
#include <stdio.h>

/* BUILT INS */
int kj_help(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    puts(MESSAGE_SPLASH);
    puts(MESSAGE_HELP);

    return 0;
}
