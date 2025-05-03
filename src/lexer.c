#include "lexer.h"

#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "hash.h"

struct token get_token_command(char *word) {
    enum token_type type;
    char *value = malloc(strlen(word));
    strcpy(value, word);

    switch(hash_string(word)) {
    case HASH_HELP:
    case HASH_CLEAR:
    case HASH_EXIT:
        type = BUILTIN;
    default:
        type = EXTERN;
    }

    return (struct token){type, value};
}

struct token get_token_argument(char *word);

struct token *tokenize_line(char *line) {
    int len = 1;
    for(int i = 0;; i++) {
        if(line[i] == ' ')
            len += 1;
    }

    struct token *tokens = malloc(sizeof(struct token) * len);

    char *word = strtok(line, " ");

    tokens[0] = get_token_command(word);
    for(int i = 1; word != NULL; i++) {
        tokens[i] = get_token_argument(word);
        word = strtok(NULL, " ");
    }

    return tokens;
}
