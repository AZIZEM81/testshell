#include "newss.h"

/**
 * check_exit_command - Checks if the command is an exit command.
 * @cmd: The command to check.
 * @status: Pointer to the status of the command.
 *
 * Returns: 1 if the command is not "exit", otherwise exits the shell.
 */
int check_exit_command(char *cmd, int *status) {
	// Check if the command is "exit"
	if (_strcmp(cmd, "exit") == 0) {
		// If the status is not 0, exit with code 2, otherwise exit with code 0
		exit(*status != 0 ? 2 : 0);
	}
	// Return 1 to continue shell execution
	return 1;
}

/**
 * read_user_input - Reads user input from stdin.
 *
 * Returns: Input read from stdin.
 */
char *read_user_input(void) {
	// Read input from stdin using getline
	char *input = NULL;
	size_t bufsize = 0;
	ssize_t characters = getline(&input, &bufsize, stdin);
	// Handle input errors
	if (characters == -1) {
		free(input);
		if (isatty(STDIN_FILENO)) {
			putchar('\n');
		}
		return NULL;
	}
	// Remove trailing newline character
	if (input[characters - 1] == '\n') {
		input[characters - 1] = '\0';
	}
	return input;
}

/**
 * check_env_command - Checks if the command is an environment command.
 * @cmd: The command to check.
 *
 * Returns: 0 if the command is "env", 1 otherwise.
 */
int check_env_command(char *cmd) {
	// Check if the command is "env"
	if (_strcmp(cmd, "env") == 0) {
		// Print all environment variables
		int i = 0;
		while (environ[i]) {
			_puts(environ[i++]);
		}
		free(cmd);
		return 0;
	}
	// Return 1 to continue shell execution
	return 1;
}

/**
 * print_error_message - Prints an error message for failed command execution.
 * @cmd: The command that caused the error.
 * @prog_name: Name of the program.
 */
void print_error_message(char *cmd, const char *prog_name) {
	// Print error message indicating command not found
	if (isatty(STDIN_FILENO)) {
		write(STDOUT_FILENO, cmd, _strlen(cmd));
		write(STDOUT_FILENO, ": command not found\n", 20);
	} else {
		write(STDERR_FILENO, prog_name, _strlen(prog_name));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, cmd, _strlen(cmd));
		write(STDERR_FILENO, ": not found\n", 12);
	}
}

/**
 * get_env_var - Gets the value of an environment variable.
 * @name: The name of the variable.
 *
 * Returns: The value of the variable, or NULL if not found.
 */
char *get_env_var(const char *name) {
	// Find the environment variable by name
	int i = 0;
	size_t len = _strlen(name);
	while (environ[i]) {
		if (_strncmp(name, environ[i], len) == 0 && environ[i][len] == '=') {
			// Return the value of the environment variable
			return &environ[i][len + 1];
		}
		i++;
	}
	// Return NULL if the environment variable is not found
	return NULL;
}
