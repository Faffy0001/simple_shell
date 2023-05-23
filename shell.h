#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>


char *string_concat(char *dest, char *src);
int string_compare(char *s1, char *s2);
int string_length(char *s);
size_t string_compare_n(char *s1, char *s2, size_t n);
char *string_copy(char *dest, char *src);
char **parse_input(char *input_str);
int find_executable_path(char **command, char **env_vars);
int num_builtins(void);
int change_directory(char **args);
int display_help(char **args);
int exit_shell(char **args);
int handle_ctrld(char **args);
int whitespace_check(const char *str);
char *get_path_string(char **env);
char *getline_command(void);
void get_env(char **env);
int my_fork(char **com, char **arg, char **env, char *line, int nmp, int isp);
#endif
