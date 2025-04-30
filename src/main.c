#include <stdlib.h>
#include <stdio.h>

#include "builtins/clear.h"
#include "builtins/help.h"
#include "messages.h"
#include "hash.h"


int main() {
    char line[2048];
    int kj_ret;

    while(1) {
        printf("$ "); // TODO: more complete prompt with env var support

        if(fgets(line, sizeof(line), stdin)) {
            int input_hash = hash_string(line);
            switch(input_hash) { // TODO: consider function pointers
            case HASH_EMPTY_LINE:
                break;
            case HASH_HELP:
                kj_ret = kj_help();
                break;
            case HASH_CLEAR:
                kj_ret = kj_clear();
                break;
            case HASH_EXIT:
                exit(EXIT_SUCCESS);
            default:
                printf(MESSAGE_UNKOWN_COMMAND, line);
                kj_ret = -1;
            }
        }
    }

    (void)kj_ret;
    return EXIT_SUCCESS;
}
