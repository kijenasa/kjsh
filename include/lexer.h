#ifndef LEXER_H
#define LEXER_H

enum token_type {
    BUILTIN,
    EXTERN,
    ARGUMENT,
};

struct token {
    enum token_type type;
    char *data;
};

// Returned token's data is heap allocated
// *Remember to free()*
struct token *tokenize_line(char *line);

#endif
