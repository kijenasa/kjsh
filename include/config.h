#ifndef CONFIG_H
#define CONFIG_H

#define ENVIRONMENT_VARIABLE_TABLE_SIZE 1024

// Builtin hash definitions
enum {
    HASH_HELP = 693,
    HASH_CLEAR = 1107,
    HASH_EXPORT = 1,
    HASH_EXIT = 718,
    HASH_EMPTY_LINE = 0,
};

// Messages
#define CLEAR_SCREEN "\e[1;1H\e[2J"

#define MESSAGE_UNKOWN_COMMAND "UNKOWN COMMAND: %s\n Try \"help\"\n"
#define MESSAGE_SPLASH "kjsh"

#define MESSAGE_HELP                                                                                                   \
    "Built in commands:\n\
    help\n\
    exit\n"

#endif
