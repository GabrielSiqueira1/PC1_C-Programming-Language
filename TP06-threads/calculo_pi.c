#include <pthread.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/resource.h>

#define BILLION 1000000000.0

unsigned numthreads;
double *resultados;
unsigned prints;

void* func(void * id){
	long ID=(long)id;
	pid_t tid;
	tid = syscall(SYS_gettid);
	if (prints) 
        printf("Thread: %4ld(%d) - Process ID: %5d Pai:%5d\n",ID,tid,getpid(),getppid());
	double sum =0.0,x;
	unsigned long long int i;
    unsigned long long int passos = 1*BILLION;
	double h=1.0/passos;
	for (i = ID + 1; i <= passos; i += numthreads) {
		x = h * ((double)i - 0.5); 
		sum += 4.0 / (1.0 + x*x); 
	}
	resultados[ID]=h*sum;
	pthread_exit(NULL);
}

int main(int argc, char *argv[]){	

	// variáveis utilizadas para medir o tempo de execução.
	struct timespec start, end;
	clock_gettime(CLOCK_REALTIME, &start);
    if(argc==3){
        numthreads = atoi(argv[1]);
        prints = atoi(argv[2]);
    }
    else{
        printf("Para executar o programa informe 2 parâmetros.\n");
        printf(" O primeiro deve ser o número de threads que irá calcular o valor de pi.\n");
        printf(" O segundo deve ser um valor lógico (0 ou 1).\n");
        printf("   Se 1, então serão impressas algumas informações sobre a execução.\n");
        printf("   Se 0, serão impressos apenas o número de threads e o tempo gasto.\n");
        printf("\nExemplos:\n$./a.out 2 0\n$./a.out 2 1\n");
        return 1;
    }
    resultados = malloc(numthreads*sizeof(double));
	pid_t tid;
	tid = syscall(SYS_gettid);
    if(prints)
	    printf("Thread: main(%d) - Process ID: %5d Pai:%5d\n",tid,getpid(),getppid());

	//Idenficador de cada thread
	pthread_t handles[numthreads];
 
	/*Carrega os atributos padrões para criação
	 das threads. Dentre os atributos, estão:
	prioridade no escalonamento e tamanho da pilha.*/
	pthread_attr_t attr; 
	pthread_attr_init(&attr);

	//Cria as threads usando os atributos carregados.
	long i;
	for (i = 0; i < numthreads; i++){
		pthread_create(&handles[i], &attr, func, (void*)i);
	}

	// Espera todas as threads terminarem.
	for (i = 0; i != numthreads; ++i)
		pthread_join(handles[i], NULL); //NULL -> parâmetro de retorno

	/* Soma o resultado de cada thread.*/
	double pi=0.0;
	for (i = 0; i != numthreads; ++i)		
		pi=pi+resultados[i]; 
	if(prints) 
        printf("\nValor de pi %.8f",pi);

    //Pega o tempo novamente para calcular o tempo de execução
	clock_gettime(CLOCK_REALTIME, &end);
	// time_spent = end - start
	double time_spent = (end.tv_sec - start.tv_sec) +
						(end.tv_nsec - start.tv_nsec) / BILLION;
	
	struct rusage ru;
	//Leitura das informacoes do processo.
	getrusage(RUSAGE_SELF, &ru);
	if(prints){
        printf("\nNúmero de threads: %d.\nTempo gasto: %f segundos.", numthreads, time_spent);
        printf("\nTempo de processador no modo usuário: %.5f segundos.\n",ru.ru_utime.tv_sec+ ru.ru_utime.tv_usec/1000000.0);
    }
    else
        printf("%d %f\n", numthreads, time_spent);

	return 0;
}
