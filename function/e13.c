#include <stdio.h>
#include <stdlib.h>

int fatorial(int x){

    int mult=1,i;
    for (i=0;i<x;i++){
        mult=mult*(x-i);
    }
    return mult;
}

int potencia(int base,int expoente){
    int mult=1,i;
    for(i=1;i<=expoente;i++){
        mult=mult*base;
    }
    return mult;
}

float somatorio(int n){
    float sum=0;
    int i;
    for (i=3;i<=n;i++){
        sum=sum+(fatorial(i)/(float)potencia(i,i));
    }
    return sum;
}

int main(){

    int n;
    scanf("%d",&n);

    printf("%f\n",somatorio(n));

    system("PAUSE");
    return 0;
}
