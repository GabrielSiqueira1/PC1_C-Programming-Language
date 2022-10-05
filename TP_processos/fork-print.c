#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main ()
{
   int retval, x ;

   x = 0 ;
   retval = fork () ;
   printf ("No processo %5d x vale %d\n", getpid(), x) ;
   if ( retval < 0 ){
      perror ("Erro") ;
      exit (1) ;
   }
   else
      if ( retval > 0 ){
         x = 0 ;
         wait (0) ;
      }
      else{
         x++ ;
         sleep (5) ;
      }

   printf ("No processo %5d x vale %d\n", getpid(), x) ;

   exit (0) ;
}
