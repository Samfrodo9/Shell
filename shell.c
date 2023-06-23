#include "shell.h"

/**
 * main - The main Shell
 * @ac: argument to main
 * @av: argument to main
 * @env: argument to main
 *
 * Return: Always 0.
 */
int main(int ac, char *av[], char *env[])
{
	char **store = NULL;
	int i = 0;

	printf("$ ");
	store= _getinput();
	while(store[i] != NULL)
	{
		printf("%s\n", store[i]);
		i++;
	}
	
	for (i = 0; store[i] != NULL; i++) /* Freeing the array of strings */
	{
		free(store[i]);
	}
		free(store);

	return (0);
}
