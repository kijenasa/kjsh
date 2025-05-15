#include "builtins/say.h"

#include <stdio.h>

int kj_say(int argc, char *argv[]) {
    if(argc < 2)
        return -1;

    puts(argv[1]);

    return 0;
}
