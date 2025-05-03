#include "lexer.h"

#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "hash.h"
#include "env.h"

static struct token get_token_command(char *word) {
    enum token_type type;

    if(word[0] == '$')
        word = get_environment_variable(&word[1]);

    char *value = malloc(strlen(word));
    strcpy(value, word);

    switch(hash_string(word)) {
    case HASH_HELP:
    case HASH_CLEAR:
    case HASH_EXIT:
        type = BUILTIN;
        break;
    default:
        type = EXTERN;
    }

    return (struct token){type, value};
}

static struct token get_token_argument(char *word) {
    enum token_type type = ARGUMENT;

    if(word[0] == '$')
        word = get_environment_variable(&word[1]);

    char *value = malloc(strlen(word));
    strcpy(value, word);

    return (struct token){type, value};
}

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
