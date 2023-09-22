#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
void line_to_array(char *user_input, char *program_name, char **envp);
void execute_tokens(char **tokenarr, char *program_name, char **envp);
void free_tokenarr(char **tokenarr, int i, char *user_input_cp);
void get_line_function(char *program_name, char **envp);
void process_user_input(char *user_input, char *program_name, char **envp);
void handle_error(char *user_input);
void env_builtin(char **envp);
char *_strdp(const char *str);
int _strcmp(const char *str1, const char *str2);
int is_whitespace_string(const char *str);
int is_empty_input(const char *user_input, int is_pipe);
void trim_whitespace(char *str);
#endif
