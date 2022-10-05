#include <stdio.h>
#include <sys/resource.h>

int main(int argc, char *argv[]){
	int a,b;
	for (a=0;a<1999999999;a++);

	struct rusage ru;
	//Leitura das informacoes do processo.
	getrusage(RUSAGE_SELF, &ru);
	printf("\nTrocas involuntarias: %5ld \nTrocas voluntarias: %5ld",
																		ru.ru_nivcsw,ru.ru_nvcsw);
	printf("\nUser mode: %.5f (secs).\nKernel mode: %.5f (secs.)\n",
										ru.ru_utime.tv_sec+ ru.ru_utime.tv_usec/1000000.0,
										ru.ru_stime.tv_sec+ ru.ru_stime.tv_usec/1000000.0);
	return 0;
}


