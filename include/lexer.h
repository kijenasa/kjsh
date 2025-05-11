#ifndef LEXER_H
#define LEXER_H

enum token_type {
    BUILTIN,
    EXTERN,
    ARGUMENT,
    END,
};

struct token {
    enum token_type type;
    char *data;
};

// Returned token's data is heap allocated
// *Remember to free()*
struct token *tokenize_line(char *line);

// free()'s *tokens, but not the *data of the tokens
char **detokenize_line(struct token *tokens);

#endif
