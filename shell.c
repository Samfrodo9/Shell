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
	int i = 0, forkRV, status;
	while(9)
	{
		i = 0;
		printf("$ ");
		store = _getinput();
		if (store == NULL)
		{
			return (-1);
		}
		forkRV = fork();
		if (forkRV == -1)
		{
			perror("Error: ");
			return (1);
		}
		if (forkRV == 0)
		{
			 if (execve(store[0], store, env) == -1)
			 {
				 perror("Error: ");
				 return (1);
			 }
		}
		else
		{
			wait(&status);
			printf("Parent\n");
		}
		
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
	}
	return (0);
}
