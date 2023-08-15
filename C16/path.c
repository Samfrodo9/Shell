#include "shell.h"
#include <string.h>

/**
 * A session to explain the concept of Paths in Simple Shell
 */

int main(char ac, char **argv)
{
	struct stat st;
	char *store = NULL;
	char *store2 = NULL;
	char fullPath[50];
	int i = 0, flag = 0;
	store = getenv("PATH");

	store2 = strtok(store, ":");

	do {
		strcpy(fullPath, store2);
		printf("Fullpath[%d] is %s\n", i, fullPath);

		strcat(fullPath, "/");
		printf("Fullpath[%d] is now %s\n", i, fullPath);

		strcat(fullPath, argv[1]);
		printf("Fullpath[%d] is now %s\n", i, fullPath);

		if (stat(fullPath, &st) == 0)
		{
			printf("%s found\n", fullPath);
			flag = 1;
			return (0);
		}

	i++;
	} while(store2 = strtok(NULL, ":"));


	if (flag == 1)
		printf("%s found\n", fullPath);
	else
		 printf("%s not found\n", fullPath);

	return (0);
}
