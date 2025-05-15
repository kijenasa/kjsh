#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"
#include "execute.h"

int main() {
    char line[2048];

    while(1) {
        printf("$ "); // TODO: more complete prompt with env var support

        if(fgets(line, sizeof(line), stdin)) {
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
