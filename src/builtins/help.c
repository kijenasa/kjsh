#include "builtins/help.h"

#include "messages.h"
#include <stdio.h>

/* BUILT INS */
int kj_help() {
    puts(MESSAGE_SPLASH);
    puts(MESSAGE_HELP);

    return 0;
}
