#ifndef ENV_H
#define ENV_H

int add_environment_variable(char *name, char *value);
int remove_environment_variable(char *name); // Will free() the pointer

char *get_environment_variable(char *name);
int set_environment_variable(char *name, char *value);

#endif
