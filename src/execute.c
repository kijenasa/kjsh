#include "execute.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "hash.h"
#include "config.h"
#include "builtins/clear.h"
#include "builtins/export.h"
#include "builtins/say.h"
#include "builtins/help.h"
#include "builtins/exit.h"
#include "lexer.h"

// get_builtin(char *command) -> builtin(int argc, char *argv[])
static int (*get_builtin(char *command))(int, char *[]) {
    int (*builtin)(int, char *[]) = NULL;

    int input_hash = hash_string(command);
    switch(input_hash) { // TODO: consider function pointers
    case HASH_EMPTY_LINE:
        break;
    case HASH_HELP:
        builtin = &kj_help;
        break;
    case HASH_CLEAR:
        builtin = &kj_clear;
        break;
    case HASH_EXPORT:
        builtin = &kj_export;
        break;
    case HASH_SAY:
        builtin = &kj_say;
        break;
    case HASH_EXIT:
        builtin = &kj_exit;
        break;
    default:
        break;
        // TODO: kj_unknown()
    }

    return builtin;
}

//int run_external(char *path, char *argv[]) {
//    // NOTE: final element in argv must be NULL
//
//    pid_t pid = fork();
//    int status;
//    if(pid < 0) {
//        perror("Failed to fork()");
//    } else if(pid == 0) {
//        execvp(argv[0], argv);
//    } else {
//        waitpid(pid, &status, 0);
//        return WEXITSTATUS(status);
//    }
//}

/*
 * Turn tokens data into argc argv format
 * Attempt to get_builtin(),
 * if it returns NULL, search $PATH
 * if found, idk execute it
 */
int execute(struct token *tokens) {
    int argc = 0;
    while(tokens[argc].type != END)
        argc++;

    struct token command_name = tokens[0];
    int (*command)(int, char *[]);
    command = get_builtin(command_name.data);
    char **argv = detokenize_line(tokens);

    if(command != NULL) {
        command(argc, argv);
    }

    (void)tokens;
    return -1;
}
