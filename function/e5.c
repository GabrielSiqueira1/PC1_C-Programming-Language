#include <stdio.h>
#include <stdlib.h>

int bissexto(int ano){
    if((ano%100!=0 && ano%4==0) || (ano%100==0 && ano%400==0))
        return 1;
    else
        return 0;
}

int main(){

    int ano;
    scanf("%d",&ano);

    if (bissexto(ano))
        printf("E bissexto\n");
    else
        printf("Nao e bissexto\n");

    system("PAUSE");
    return 0;
}
