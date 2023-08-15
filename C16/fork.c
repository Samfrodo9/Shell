#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void)
{
	int status = 100;
	pid_t forkRV;

	printf("Before calling fork function\n");

	forkRV = fork(); /* Two processes are now running */
	
	printf("Wait status is %d\n", status);

	if (forkRV == -1)
	{
		perror("Process Creation failed\n");
		return (-1);
	}

	if (forkRV == 0)
	{
		printf("I am in the child process\n");

		printf("Child PID is %u\n", getpid());
		printf("PPID of the child is %u\n", getppid());
	}

	else
	{
		wait(&status);
		printf("Wait status of child is %u\n", status);
		printf("I am the parent\n");

		printf("My child PID is %u and my PID is %u\n", forkRV, getpid());
		
	}

	printf("I will be printed twice\n");


	return (0);
}
