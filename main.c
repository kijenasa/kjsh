#include <stdlib.h>
#include <stdio.h>

/* BUILT INS */
//int kj_help() { return -1; }
//int kj_ls(const char *dir) { return -1; }
//int kj_cd(const char *dir) { return -1; }
//int kj_exit() { return -1; }

/* ENTRY */
int main() {
    while(1) {
        char line[2048];
        if(fgets(line, sizeof(line), stdin)) {
            printf("YOU ENTERED %s\n", line);
        }
    }
    return EXIT_SUCCESS;
}
