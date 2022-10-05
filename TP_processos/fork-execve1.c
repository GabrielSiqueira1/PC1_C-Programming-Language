#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/*O terceiro argumento "envp" serve para acessar as variáveis de ambiente do sistema.*/
int main (int argc, char *argv[], char *envp[])
{
   int retval ;

   printf ("Ola, sou o processo %5d\n", getpid()) ;


  
   retval = fork () ;

 for(int i = 0; i < 100000000; i++){}
 
   printf ("[retval: %5d] sou %5d, filho de %5d\n",retval, getpid(), getppid()) ;
   if ( retval < 0 )
   {
      perror ("Erro: ") ;
      exit (1) ;
   }
   else
      if ( retval > 0 ){ //Se pai
			int status;
			int id = wait (&status) ; 
			printf("%d terminou com status %d\n",id,WEXITSTATUS(status));
		}
      else{
	 /*Observe que o processo "simple" possui o mesmo id do processo filho que acabou de ser criado.*/
         execve ("./simple", argv, envp) ;
         perror ("Erro");/*Essa mensagem ocorrera' apenas quando houver erro ao fazer o 'load' do "./simple" */
      }
   printf ("Tchau de %5d!\n",getpid()) ;
   exit (0) ;
}
