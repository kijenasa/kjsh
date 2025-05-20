#include "builtins/cd.h"

#include <stdio.h>
#include <unistd.h>

int kj_cd(int argc, char *argv[]) {
    if(argc < 2)
        return -1;

    chdir(argv[1]);

    return 0;
}
