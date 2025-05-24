#include "builtins/run.h"

#include "script.h"

int kj_run(int argc, char *argv[]) {
    if(argc < 2)
        return -1;

    return run_script(argv[1]);
}
