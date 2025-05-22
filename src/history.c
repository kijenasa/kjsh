#include "history.h"

#include <stdlib.h>
#include <stdio.h>
#include "config.h"

FILE *fhistory;

int init_history() { // TODO: fix history being reset every time
    char *home = getenv("HOME");
    char path[1024];
    sprintf(path, "%s/%s", home, HISTORY_PATH);

    fhistory = fopen(path, "a");

    if(fhistory == NULL)
        return -1; 

    return 0;
}

char *get_history(int index);

int add_history(char *line) {
    return fputs(line, fhistory);
}
