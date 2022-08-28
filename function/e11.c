#include <stdio.h>
#include <stdlib.h>

int potencia(int base,int expoente){
    int mult=1,i;
    for(i=1;i<=expoente;i++){
        mult=mult*base;
    }
    return mult;
}

int main(){
    int a,b;
    scanf("%d^%d",&a,&b);

    printf("%d\n",potencia(a,b));
}
