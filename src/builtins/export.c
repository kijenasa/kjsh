#include "builtins/export.h"

#include "env.h"

int kj_export(char *name, char *value) {
    return add_environment_variable(name, value);
}
