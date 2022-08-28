#include <stdio.h>
#include <stdlib.h>

int potencia(int base,int expoente){
    int mult=1,i;
    for(i=1;i<=expoente;i++){
        mult=mult*base;
    }
    return mult;
}

float VAL(float x,int n, float t){
    float valor = 0;
    for (n;n>=1;n--){
        valor = valor + x/(potencia((1+t),n));
    }
    return valor;
}

int main(){

    int anos;
    float auxiliar,taxa;

    scanf("%f",&auxiliar);
    scanf(" %d",&anos);
    scanf(" %f",&taxa);
    printf("%f\n",VAL(auxiliar,anos,taxa));


    system("PAUSE");
    return 0;
}
