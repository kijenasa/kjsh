#include "history.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "config.h"

FILE *fhistory;

int init_history() {
    char *home = getenv("HOME");
    char path[1024];
    sprintf(path, "%s/%s", home, HISTORY_PATH);

    fhistory = fopen(path, "a");

    if(fhistory == NULL)
        return -1;

    return 0;
}

int get_history(int index, char *line) {
    int i = 0;
    while(fgets(line, sizeof(line), fhistory)) {
        if(i == index)
            break;
        i++;
    }

    return 0;
}

int close_history() { return fclose(fhistory); }

int add_history(char *line) { return fputs(line, fhistory); }
