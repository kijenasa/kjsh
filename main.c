#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/* MACROS ENUMS */

enum {
    HASH_HELP = 435,
    HASH_LS = 223,
    HASH_CD = 199,
    HASH_EXIT = 442,
    HASH_EMPTY_LINE =  10,
};

#define MESSAGE_UNKOWN_COMMAND "UNKOWN COMMAND: %s\n Try \"help\"\n"
#define MESSAGE_SPLASH "kjsh"
#define MESSAGE_HELP                                                                                                   \
    "Built in commands:\n\
    help\n\
    ls\n\
    cd\n\
    exit\n"

/* BUILT INS */
int kj_help() {
    puts(MESSAGE_SPLASH);
    puts(MESSAGE_HELP);

    return 0;
}
// int kj_ls(const char *dir) { return -1; }
// int kj_cd(const char *dir) { return -1; }
// int kj_clear() { return -1; }
// int kj_exit() { return -1; }

/* IDK WHAT TO CALL THIS SECTION */
int hash_string(const char *str) {
    int sum = 0;
    for(int i = 0; str[i] != '\0'; i++)
        sum += (int)str[i];

    return sum;
}

/* ENTRY */
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
            default:
                printf(MESSAGE_UNKOWN_COMMAND, line);
                printf("%d\n", hash_string(line));
                kj_ret = -1;
            }
        }
    }

    (void)kj_ret;
    return EXIT_SUCCESS;
}
