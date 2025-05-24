#include "script.h"

#include <stdlib.h>
#include <stdio.h>
#include "config.h"
#include "execute.h"

int run_script(char *name) {
#ifdef DEBUG
    printf("RUNNING SCRIPT %s\n", name);
#endif

    FILE *fscript = fopen(name, "a+");
    char line[LINE_LENGTH];

    while(fgets(line, sizeof(line), fscript)) {
        for(int i = 0; i < LINE_LENGTH; i++) {
            if(line[i] == '\n')
                line[i] = '\0';
        }

        struct token *tokens = tokenize_line(line);
        execute(tokens);
    }

    return -1;
}

int run_init() {
    char *home = getenv("HOME");
    char path[1024];
    sprintf(path, "%s/%s", home, INIT_PATH);

    return run_script(path);
}
