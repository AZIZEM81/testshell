#endif /* NEW_SS_H */
#include "new_ss.h"

/**
 * tokenize_input - Tokenize input
 * @input: Input to tokenize
 * Return: Tokenized input
 */
char **tokenize_input(const char *input)
{
	char *str;
	int count = 0;
	char **result;
	char *token;

	str = _strdup(input);
	result = malloc(MAX_TOKENS_NUM * sizeof(*result));

	token = strtok(str, " \n\t");

	while (token != NULL && count < MAX_TOKENS_NUM - 1)
	{
		if (_strlen(token) > 0)
		{
			result[count] = _strdup(token);
			count++;
		}
		token = strtok(NULL, " \n\t");
	}

	result[count] = NULL;
	free(str);

	return result;
}

/**
 * free_string_array - Free string array
 * @array: Array to free
 */
void free_str_array(char **array)
{
	int i;

	for (i = 0; array[i]; ++i)
		free(array[i]);
	free(array);
}
