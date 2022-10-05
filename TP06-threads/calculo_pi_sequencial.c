
#include <stdio.h>
#include <stdlib.h>


double pi(){
	double sum =0.0,x;
	unsigned int i;
	double h=1.0/1000000000;
	for (i = 1; i <= 1000000000; i += 1) { //1bi
		x = h * ((double)i - 0.5); 
		sum += 4.0 / (1.0 + x*x); 
	}
	return h*sum;
}

int main()
{
	printf("Valor de pi %.8f",pi());
	return 0;
}
