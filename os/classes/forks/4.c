#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main (void) 
{
        pid_t pid;

        char read_msg[BUFFER_SIZE];
        char write_msg[BUFFER_SIZE] = "Hello World!";
        
        int fd[2];

        if (pipe(fd) == -1) /*stablishes 'fd' as a bridge for interprocess comunication*/
        {
                fprintf(stderr, "Pipe failed");

                return 1;
        }

        pid = fork(); /*forks into a child process*/

        if (pid < 0)
        {
                fprintf(stderr, "Fork failed");

                return 1;
        }

        else if (pid == 0) /*child process*/
        {
                close(fd[READ_END]);

                write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);

                close(fd[WRITE_END]);
        }

        else /*parent process*/
        {
                close(fd[WRITE_END]);

                read(fd[READ_END], read_msg, BUFFER_SIZE);

                printf("Child process wrote and parent process reads: %s\n", read_msg);

                close(fd[READ_END]);
        }

        return 0;
}