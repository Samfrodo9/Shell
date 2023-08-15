#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * A session to demostrate fork and wait
 */

int main(void)
{
	char *_getline[] = {"./echoo", NULL};
	int execvRV = 10;
	pid_t forkRV;
	int waitstatus, i;

	printf("Before calling Execve\n\n\n");
	
	for (i =  0; i < 5; i++)
	{
		forkRV = fork();
	
		if (forkRV == -1)
		{
			perror("Error creating a new process");
			return (-1);
		}

		if (forkRV == 0)
		{
			execvRV = execve(_getline[0], _getline, NULL);
			if (execvRV == -1)
				{
					perror("Error ");
					exit(EXIT_FAILURE);
				}
				printf("This wont be printed\n");
		}	

		else
		{
			wait(&waitstatus);
			printf("\nChild[%d] pid = %u\n", i+1, forkRV);

			printf("Child[%d] has been terminated\n", i+1);
		}	

	}

	return (0);
}
