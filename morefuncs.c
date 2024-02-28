#include "new_ss.h"

/**
 * execute_command_from_path - Execute command from path
 * @info: Command information
 * @status: Status of the command
 */
void execute_command_from_path(CmdInfo *info, int *status)
{
	(void)status;

	if (info->full_path != NULL && access(info->full_path, F_OK | X_OK) == 0)
	{
		if (execve(info->full_path, info->args, environ) != -1)
		{
			free_str_array(info->args);
			free(info->full_path);
			exit(EXIT_SUCCESS);
		}
	}

	print_execution_error(info->cmd, info->prog_name);
	free_str_array(info->args);
	free(info->cmd);
	free(info->full_path);
	exit(127);
}

/**
 * execute_command - Execute command
 * @cmd: Command to execute
 * @status: Status of the command
 * @prog_name: Name of the program
 */
void execute_command(char *cmd, int *status, const char *prog_name)
{
	pid_t pid;
	char **args = NULL;
	char *full_path = NULL;
	CmdInfo cmd_info;

	pid = fork();
	if (pid == 0)
	{
		args = tokenize_input(cmd);
		if (args == NULL || args[0] == NULL)
		{
			free_str_array(args);
			free(cmd);
			_exit(EXIT_FAILURE);
		}
		full_path = find_executable_path(args[0], get_env_variable("PATH"));

		cmd_info.cmd = cmd;
		cmd_info.args = args;
		cmd_info.full_path = full_path;
		cmd_info.prog_name = prog_name;

		execute_command_from_path(&cmd_info, status);
	}
	else
	{
		wait(status);
		*status = WIFEXITED(*status) ? WEXITSTATUS(*status) : 127;
	}
	free(cmd);
}

/**
 * find_executable_path - Find executable path
 * @cmd: Command to execute
 * @search_path: Search path
 * Return: Full path of the command
 */
char *find_executable_path(char *cmd, char *search_path)
{
	char *path_copy = NULL, *dir = NULL, *full_path = NULL;

	if (search_path == NULL || cmd == NULL)
		return NULL;

	path_copy = _strdup(search_path);
	dir = strtok(path_copy, ":");

	while (dir)
	{
		full_path = malloc(_strlen(dir) + 1 + _strlen(cmd) + 1);

		if (full_path == NULL)
		{
			free(path_copy);
			return NULL;
		}

		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return full_path;
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return NULL;
}
