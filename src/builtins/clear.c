#include "builtins/clear.h"

#include "messages.h"
#include <stdio.h>

int kj_clear() {
    puts(CLEAR_SCREEN);
    return 0;
}
