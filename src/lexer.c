#include "lexer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "hash.h"
#include "env.h"

static struct token get_token_command(char *word) {
    if(word == NULL) {
        return (struct token){ARGUMENT, NULL};
    }

    enum token_type type;

    if(word[0] == '$')
        word = get_environment_variable(&word[1]);

    char *value = "\0";
    if(word != NULL) {
        value = malloc(strlen(word));
        strcpy(value, word);
    }

    switch(hash_string(word)) {
    case HASH_HELP:
    case HASH_CLEAR:
    case HASH_EXIT:
        type = BUILTIN;
        break;
    default:
        type = EXTERN;
    }

#ifdef DEBUG
    printf("TOKEN COMMAND: %s\n", value);
#endif

    return (struct token){type, value};
}

static struct token get_token_argument(char *word) {
    if(word == NULL) {
        return (struct token){ARGUMENT, NULL};
    }

    enum token_type type = ARGUMENT;
    char *value = "\0";

    if(word[0] == '$')
        word = get_environment_variable(&word[1]);

    if(word != NULL) {
        value = malloc(strlen(word));
        strcpy(value, word);
    }

#ifdef DEBUG
    printf("TOKEN ARGUMENT: %s\n", value);
#endif

    return (struct token){type, value};
}

struct token *tokenize_line(char *line) {
    int len = 1;
    for(int i = 0; line[i] != '\0'; i++) {
        if(line[i] == ' ')
            len += 1;
    }

#ifdef DEBUG
    printf("TOKENIZE_LINE LEN: %d\n", len);
#endif

    struct token *tokens = malloc(sizeof(struct token) * (len + 1));

    char *word = strtok(line, " ");

    tokens[0] = get_token_command(word);
    for(int i = 1; i < len; i++) {
        word = strtok(NULL, " ");
        if(word != NULL) {
#ifdef DEBUG
            printf("TOKENIZE_LINE GETTING TOKEN FOR INDEX %d\n", i);
#endif
            tokens[i] = get_token_argument(word);
        } else {
            break;
        }
    }

    tokens[len] = (struct token){ARGUMENT, NULL}; // Null terminate

    return tokens;
}

/* NOTE:
 * Doing it like this defeats the point of using a lexer almost interiely
 * (the only benefit of it now is environment varialbes)
 * however it is kept like this for future updates to the lexer.
 */
char **detokenize_line(struct token *tokens) {
    int argc = 1;
    while(tokens[argc].data != NULL)
        argc++;

    char **argv = malloc(sizeof(char *) * argc);

    for(int i = 0; i < argc; i++) {
        argv[i] = tokens[i].data;
    }

    free(tokens);
    return argv;
}
