#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>

//Exibe o tempo de execução do processo (no modo usuário)
void exibir_tempo(){
	struct rusage ru;
	getrusage(RUSAGE_SELF, &ru);
	printf("\nTempo (modo usuário) %.5f (secs)\n",ru.ru_utime.tv_sec+ ru.ru_utime.tv_usec/1000000.0);
    //printf("\nTrocas involuntarias: %5ld \nTrocas voluntarias: %5ld", ru.ru_nivcsw,ru.ru_nvcsw);

}


int main (){
	printf ("Simple.c - sou %5d, filho de %5d\n", getpid(), getppid()) ;
    exibir_tempo();

	return 0;


}
