#include "builtins/export.h"

#include "env.h"

int kj_export(int argc, char *argv[]) {
    char *name;
    char *value;
    if(argc <= 3) {
        return -1;
    }

    name = argv[1];
    value = argv[2];
    return add_environment_variable(name, value);
}
