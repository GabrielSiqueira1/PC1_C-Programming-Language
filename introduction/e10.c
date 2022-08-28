#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float max (float *v, int n){
    int index;
    float nb;
    for (index=0;index<n;index++){
        if (index==0 || v[index]>=nb){
            nb=v[index];
        }
    }
    return nb;
}

void main(){

    int index,N,n;
    srand (time(0));
    printf("Choose vector size: ");
    scanf("%d",&N);
    getchar();
    printf("Choose the number of numbers that entered the calculation: ");
    scanf("%d",&n);
    float V[N];
    for (index=0;index<=N;index++){
        V[index]=rand()%100;
    }
    for (index=0;index<=N;index++){
        printf("%2f\n",V[index]);
    }
    printf("\n\n%f\n\n",max(V,n));

}
