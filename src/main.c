#include <stdlib.h>
#include <stdio.h>
#include "config.h"
#include "lexer.h"
#include "execute.h"
#include "history.h"

int main() {
    char line[LINE_LENGTH];
    if(init_history() != 0) {
        perror("Failed to initialize history");
    }

    while(1) {
        printf("$ "); // TODO: more complete prompt with env var support
        if(fgets(line, sizeof(line), stdin)) {
            add_history(line);
            for(int i = 0; i < 2048; i++){
                if(line[i] == '\n')
                    line[i] = '\0';
            }

            struct token *tokens = tokenize_line(line);
            execute(tokens);
        }
    }

    return EXIT_SUCCESS;
}
