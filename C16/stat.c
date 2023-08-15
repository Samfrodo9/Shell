#include "shell.h"

/**
 * A session to demostrate how to stat Files
 */

int main(int ac, char **argv)
{
	struct stat check;
	int statRV;
	int loop = 1;

	while(argv[loop])
	{
		statRV = stat(argv[loop], &check);
		if (statRV == 0)
		{
			printf("%s found\n", argv[loop]);
		}
		else
		{
			printf("%s not found\n", argv[loop]);
		}

		loop++;
	}

	return (0);
}
