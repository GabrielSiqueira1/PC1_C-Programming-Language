#include <stdio.h>
#include <stdlib.h>

int fatorial(int x){

    int mult=1,i;
    for (i=0;i<x;i++){
        mult=mult*(x-i);
    }
    return mult;
}

int somatorio(int n){
    int sum=0,i;
    for (i=3;i<=n;i++){
        sum=sum+fatorial(i);
    }
    return sum;
}

int main(){

    int num;
    scanf("%d",&num);
    printf("%d\n",somatorio(num));

    system("PAUSE");
    return 0;
}
