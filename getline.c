#include "shell.h"

/**
 * _getinput - A function that gets input from STDIN
 *
 */
char **_getinput(void)
{
	size_t size;
	char *token = NULL, *buffer = NULL, *copy = NULL;
	const char *delimeter = " \n";
	int argc = 0, i;
	char **argv = NULL;

		if (getline(&buffer, &size, STDIN) == -1)
		{
			free(buffer);
			return NULL;
		}

		copy = strdup(buffer);
		token = strtok(buffer, delimeter);
		while(token)
		{
			token = strtok(NULL, delimeter);
			argc++;
		}
		argv = malloc(sizeof(char *) * (argc + 1));
		if (argv == NULL)
		{
			  perror("Memory allocation failed\n");
			  free(buffer);
			  return NULL;
		}

		i = 0;
		token = strtok(copy, delimeter);
		while(token)
		{
			argv[i] = strdup(token);
			token = strtok(NULL, delimeter);
			i++;
		}
		argv[i] = NULL;

	free(buffer);
	free(copy);
	return (argv);
}
