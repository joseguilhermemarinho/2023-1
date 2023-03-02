#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
	pid_t fork_return, pid;

	fork_return = fork();  

	if (fork_return < 0)
	{
		fprintf(stderr, "Fork failed");
		
		return 1;
	}
	
	else if (fork_return == 0) /*child process*/
	{
		pid = getpid();
		printf("child pid -> %d\n", pid);
		printf("child fork_return -> %d\n\n", fork_return);
	}

	else /*parent process*/
	{
		pid = getpid();
		printf("parent pid -> %d\n", pid);
		printf("parent fork_return -> %d\n\n", fork_return);
		
		wait(NULL);
	}

	return 0;
}