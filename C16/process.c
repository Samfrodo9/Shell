#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(void)
{
	pid_t process_id;
	pid_t parentprocess_id;

	process_id = getpid();
	parentprocess_id = getppid();

	printf("My process id(child) is %u\n", process_id);
	printf("My parent process is %u\n", parentprocess_id);

	return (0);
}
