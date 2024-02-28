#include "newss.h"

/**
 * main - Entry point of the shell program
 * @argc: Number of arguments passed to the program
 * @argv: Array of pointers to the arguments
 * Return: Always return 0 on successful completion
 */
int main(int argc, char *argv[]) {
	char *input_buffer = NULL;          // Buffer to store user input
	int command_status = 0;             // Status of the command execution
	const char *shell_name = argv[0];   // Name of the shell program

	// Check if the shell is running in interactive mode
	if (isatty(STDIN_FILENO)) {
		// Interactive mode
		while (1) {
			// Print shell prompt
			write(STDOUT_FILENO, "$ ", 2);

			// Read user input
			input_buffer = read_user_input();

			// Check for end of file (Ctrl+D)
			if (input_buffer == NULL) {
				break;
			}

			// Check for exit command
			if (!check_exit_command(input_buffer, &command_status)) {
				free(input_buffer);
				break;
			}

			// Check for environment command
			if (!check_env_command(input_buffer)) {
				free(input_buffer);
				continue;
			}

			// Execute the command
			execute_shell_command(input_buffer, &command_status, shell_name);

			// Free the memory allocated for input buffer
			free(input_buffer);
		}
	} else {
		// Non-interactive mode
		while ((input_buffer = read_user_input()) != NULL) {
			// Check for exit command
			if (!check_exit_command(input_buffer, &command_status)) {
				free(input_buffer);
				break;
			}

			// Check for environment command
			if (!check_env_command(input_buffer)) {
				free(input_buffer);
				continue;
			}

			// Execute the command
			execute_shell_command(input_buffer, &command_status, shell_name);

			// Free the memory allocated for input buffer
			free(input_buffer);
		}
	}

	return 0;
}
