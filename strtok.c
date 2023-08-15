#include <stdio.h>
#include <string.h>

int main(void)
{
	char text[100] = "This is a simple shell series";

	printf("Before tokenizing, my string is %s\n", text);

	char *get;

	get = strtok(text, " ");
	
	while(get)
	{
		printf("%s\n", get);

		get = strtok(NULL, " ");
	}

	printf("After tokenizing twice, my string is %s\n", text + 5);

	return (0);
}

/**
 * "This is a simple shell series"
 *
 * strtok(text, " ") --> This; "This\0is a simple shell series"
 * strtok(NULL, " ") --> is; "This\0is\0a simple shell series"
 * strtok(NULL, " ") --> a; "This\0is\0a\0simple shell series"
 * strtok(NULL, " ") --> simple; "This\0is\0a\0simple\0shell series"
 * strtok(NULL, " ") --> shell; "This\0is\0a\0simple\0shell\0series"
 * strtok(NULL, " ") --> series; "This\0is\0asimple\0shell\0series\0"
 * strtok(NULL, " ") --> NULL;
 */
