#include <stdio.h>
#include <stdlib.h>

void menorNumeroMaiorDivisor(){
    int count=0,i,j,M;
    int menorNumero, quantDivisor;
    for (i=1;i<=10000;i++){
        count=0;
        for (j=1;j<=10000;j++){
            if(i%j == 0){
                count++;
            }
        }
        if(count==1 || M<count){
            M=count;
            menorNumero=i;
            quantDivisor=count;
        }
    }
    printf("%d\n",menorNumero);
    printf("%d\n",quantDivisor);
    for (i=1;i<=10000;i++){
        if(menorNumero%i==0){
            printf("%d\n",i);
        }
    }
}

int main(){

    menorNumeroMaiorDivisor();
    printf("\n");

    system("PAUSE");
    return 0;

}
