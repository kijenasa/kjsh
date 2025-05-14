#include "lexer.h"

#include <stdio.h>
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

    switch(hash_string(word)) { // TODO make this a function
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
    for(int i = 0; line[i] != '\0'; i++) {
        if(line[i] == ' ')
            len += 1;
    }

    struct token *tokens = malloc(sizeof(struct token) * (len + 1));

    char *word = strtok(line, " ");

    tokens[0] = get_token_command(word);
    for(int i = 1; word != NULL; i++) {
        word = strtok(NULL, " ");
        tokens[i] = get_token_argument(word);
    }

    tokens[len] = (struct token){END, NULL};

    return tokens;
}

/* NOTE:
 * Doing it like this defeats the point of using a lexer almost interiely
 * (the only benefit of it now is environment varialbes)
 * however it is kept like this for future updates.
 */
char **detokenize_line(struct token *tokens) {
    int argc = 0;
    while(tokens[argc].type != END)
        argc++;

    char **argv = malloc(sizeof(char *) * argc);

    for(int i = 0; i < argc; i++) {
        argv[i] = tokens[i].data;
    }

    free(tokens);
    return argv;
}
