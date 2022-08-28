#include <stdio.h>
#include <stdlib.h>

int fatorial(int x){

    int mult=1,i;
    for (i=0;i<x;i++){
        mult=mult*(x-i);
    }
    return mult;
}

int main(){

    int num;
    scanf("%d",&num);

    printf("%d\n",fatorial(num));

    system("PAUSE");
    return 0;
}
