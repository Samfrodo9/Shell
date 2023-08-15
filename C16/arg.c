#include <stdio.h>

/**
 * A session to demostrate ARGC, ARGV
 */

int main(int argc, char **argv)
{
	printf("ARGC is %d\n", argc);

	int index = 0;
	for (index = 0; index < argc; index++)
	{
		printf("ARGV[%d] = %s\n", index, argv[index]);
	}

	return (0);
}
