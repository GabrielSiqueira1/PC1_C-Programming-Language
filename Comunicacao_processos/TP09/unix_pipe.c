/**
 * Example program demonstrating UNIX pipes.
 *
 * Figures 3.25 & 3.26
 *
 * @author Silberschatz, Galvin, and Gagne
 * Operating System Concepts  - Ninth Edition
 * Copyright John Wiley & Sons - 2013
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 25
#define READ_END	0
#define WRITE_END	1

int main(void)
{
	char write_msg[BUFFER_SIZE] = "Greetings";
	char read_msg[BUFFER_SIZE];
	pid_t pid;
	int fd[2];

	/* create the pipe */
	if (pipe(fd) == -1) {
		fprintf(stderr,"Pipe failed");
		return 1;
	}

	/* now fork a child process */
	pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Fork failed");
		return 1;
	}
	if (pid > 0) {  /* parent process */
		printf("Parent: %d\n",getpid());
		/* close the unused end of the pipe */
		close(fd[READ_END]);
		sleep(5);
		/* write to the pipe */
		printf("Parent writing to the pipe: %s\n",write_msg);
		write(fd[WRITE_END], write_msg, strlen(write_msg)+1); 
		sleep(5);
		printf("Parent closing the writing end of the pipe.\n");
		/* close the write end of the pipe */
		close(fd[WRITE_END]);
	}
	else { /* child process */
		printf("Child: %d\n",getpid());
		/* close the unused end of the pipe */
		close(fd[WRITE_END]);
		/* read from the pipe */
		printf("Child (%d) waiting data from the pipe\n",getpid());
		//read blocks client as long as there is a writer.
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		printf("Child (%d) - content read from the pipe: %s\n",getpid(),read_msg);
		read_msg[0]='\0';
		/*When there are no more writers, readers are notified about that
		through read() returning the EOF.*/
		ssize_t s = read(fd[READ_END], read_msg, BUFFER_SIZE);
		if (s==0)
			printf("Child: nothing to read\n");
		else
			printf("Child (%d) reading from the pipe: %s\n",getpid(),read_msg);

		/* close the read end of the pipe */
		close(fd[READ_END]);
	}

	return 0;
}
