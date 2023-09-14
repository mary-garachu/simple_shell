#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
void line_to_array(char *user_input, char *program_name);
void execute_tokens(char **tokenarr, char *program_name);
void free_tokenarr(char **tokenarr, int i, char *user_input_cp);
void get_line_function(char *program_name);
void handle_error(char *user_input);
#endif
