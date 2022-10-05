#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM_PROCESSOS 2

int main (int argc, char *argv[], char *envp[])
{
	int retval,i;
	printf ("Ola, sou o processo %5d\n", getpid()) ;
	//Cria NUM_PROCESSOS
	for (i=0;i<NUM_PROCESSOS;i++){
		retval = fork () ;
		if (retval == 0){ //se processo filho			
			printf ("[retval: %5d] sou %5d, filho de %5d\n",
										retval, getpid(), getppid()) ;
			break;
		}
	}
	if ( retval == 0 )
		execve ("./simple", argv, envp) ;
	else
		for (i=0;i<NUM_PROCESSOS;i++)
			printf("%d terminou\n",wait(0));
	printf ("Tchau de %5d!\n",getpid()) ;
	exit (0) ;
}
