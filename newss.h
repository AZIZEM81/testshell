#ifndef MY_SHELL_H
#define MY_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TOKENS_NUM 64
extern char **environment;

typedef struct CommandData {
	char *command;
	char **arguments;
	char *full_path;
	const char *program_name;
} CommandData;

void execute_command_from_path(CommandData *info, int *exit_status);
void execute_command(char *command, int *exit_status, const char *program_name);
char *find_command_path(char *command, char *search_path);
char **tokenize_input(const char *input);
void free_argument_array(char **array);

void write_character(char c);
void write_string(const char *s);
size_t string_length(const char *s);
int compare_strings(const char *s1, const char *s2);
int compare_strings_n(const char *s1, const char *s2, size_t n);

#endif /* MY_SHELL_H */



