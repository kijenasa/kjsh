#include "builtins/export.h"

#include "env.h"
#include <stdio.h>

int kj_export(int argc, char *argv[]) {
    char *name;
    char *value;
    char *command;
    if(argc < 3) {
        return -1;
    }

    puts("getting args");
    command = argv[0];
    printf("0 %s\n", command);
    name = argv[1];
    printf("1 %s\n", name);
    value = argv[2];
    printf("2 %s\n", value);
    return add_environment_variable(name, value);
}
