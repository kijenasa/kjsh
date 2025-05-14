#include "env.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"
#include "config.h"

char *env_table[ENVIRONMENT_VARIABLE_TABLE_SIZE] = {0};

// TODO: Handle collisions

int add_environment_variable(char *name, char *value) {
    printf("ADD ENV VAR INDEX: %d\n", hash_string(name) % ENVIRONMENT_VARIABLE_TABLE_SIZE);
    int index = hash_string(name) % ENVIRONMENT_VARIABLE_TABLE_SIZE;
    char *var = malloc(strlen(value));
    strcpy(var, value);

    env_table[index] = var;

    return 0;
}

int remove_environment_variable(char *name) {
    printf("REMOVE ENV VAR INDEX: %d\n", hash_string(name) % ENVIRONMENT_VARIABLE_TABLE_SIZE);
    int index = hash_string(name) % ENVIRONMENT_VARIABLE_TABLE_SIZE;
    char **var = &env_table[index];

    if(*var == NULL)
        return -1;

    free(*var);
    *var = NULL;

    return 0;
}

char *get_environment_variable(char *name) {
    printf("GET ENV VAR INDEX: %d\n", hash_string(name) % ENVIRONMENT_VARIABLE_TABLE_SIZE);
    int index = hash_string(name) % ENVIRONMENT_VARIABLE_TABLE_SIZE;

    return env_table[index];
}

int set_environment_variable(char *name, char *value) {
    printf("SET ENV VAR INDEX: %d\n", hash_string(name) % ENVIRONMENT_VARIABLE_TABLE_SIZE);
    int index = hash_string(name) % ENVIRONMENT_VARIABLE_TABLE_SIZE;
    char **var = &env_table[index];

    if(*var == NULL)
        return -1;

    *var = value;
    return 0;
}
