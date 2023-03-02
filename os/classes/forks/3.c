#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
	int n;
	pid_t pid;

	printf("Enter the number N: ");
	scanf("%d", &n);

	pid = fork(); /*fork a child process*/ 

	if (pid < 0)
	{
		fprintf(stderr, "Fork failed");
		
		return 1;
	}
	
	else if (pid == 0) /*child process*/
	{
		while (n > 1) 
		{
			printf("%d, ", n);

			if (n % 2 == 0) 
			{
				n = n / 2;
			}
			
			else 
			{
				n = 3 * n + 1;
			}

			/*
			if (n % 2 == 0) n = n / 2
			else n = 3 * n + 1

			or 

			if (n % 2) n = 3 * n + 1
			else n = n / 2
			*/
		}

		printf("%d\n", n);
	}

	else /*parent process*/
	{
		wait(NULL);
	}

	return 0;
}