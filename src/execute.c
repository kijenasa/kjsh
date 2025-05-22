#include "execute.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "env.h"
#include "hash.h"
#include "config.h"
#include "builtins/export.h"
#include "builtins/say.h"
#include "builtins/help.h"
#include "builtins/exit.h"
#include "builtins/cd.h"
#include "lexer.h"

// get_builtin(char *command) -> builtin(int argc, char *argv[])
static int (*get_builtin(char *command))(int, char *[]) {
    int (*builtin)(int, char *[]) = NULL;

    int input_hash = hash_string(command);
    switch(input_hash) {
    case HASH_EMPTY_LINE:
        break;
    case HASH_HELP:
        builtin = &kj_help;
        break;
    case HASH_EXPORT:
        builtin = &kj_export;
        break;
    case HASH_SAY:
        builtin = &kj_say;
        break;
    case HASH_CD:
        builtin = &kj_cd;
        break;
    case HASH_EXIT:
        builtin = &kj_exit;
        break;
    default:
        break;
        // TODO: kj_unknown().
    }

    return builtin;
}

int run_external(char *argv[]) {
    int ret;
    pid_t pid = fork();
    if(pid < 0) {
        ret = -1;
        perror("Failed to fork");
    } else if(pid == 0) { // External process
        execvp(argv[0], argv);
        _exit(127);
    } else { // Shell process
        int status;
        waitpid(pid, &status, 0);

        if(WIFEXITED(status))
            ret = WEXITSTATUS(status);
        else 
            ret = -1;
    }

    return ret;
}

/*
 * Turn tokens data into argc argv format
 * Attempt to get_builtin(),
 * if it returns NULL, search $PATH
 * if found, idk execute it
 */
int execute(struct token *tokens) {
    int ret;
    int argc = 0;
    while(tokens[argc].data != NULL)
        argc++;

    struct token command_name = tokens[0];
    int (*command)(int, char *[]);
    command = get_builtin(command_name.data);
    char **argv = detokenize_line(tokens);

    if(command != NULL) {
        ret = command(argc, argv);
    } else {
        ret = run_external(argv);
    }

    char str_ret[3] = {0};
    sprintf(str_ret, "%d", ret);
    set_environment_variable("KJ_RET", str_ret);

#ifdef DEBUG
    printf("EXECUTE() RETURNING %d", ret);
#endif

    return ret;
}
