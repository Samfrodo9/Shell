#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *store = NULL;
	ssize_t size = 0;
	ssize_t getRV;
	char *temp;

	getRV = getline(&store, &size, stdin);

	if (getRV == -1)
	{
		free(store);
		exit(0);
	}
	
	printf("Before tokenizing \n");
	printf("You entered %s", store);

	printf("After tokenizing\n");

	temp = strtok(store, "\n");

	printf("You entered %s", temp); 

	free(store);

	return (0);
}
