#include <stdio.h>
#include <stdlib.h>

void calcular_tempo(int h1,int m1,int h2,int m2){
    int horaInicial, horaFinal;

    if((h1==0) || (h2==0)){
        if(h1==0){
            horaInicial=24*60+m1;
            horaFinal=h2*60+m2;
        }
        else if(h2==0){
            horaFinal=24*60+m2;
            horaInicial=h1*60+m1;
        }
        else{
            horaInicial=24*60+m1;
            horaFinal=24*60+m2;
        }
    }
    else{
        horaInicial=h1*60+m1;
        horaFinal=h2*60+m2;
    }


    if(horaInicial>horaFinal){
        printf("%d\n",1440-(horaInicial-horaFinal));
    }
    else if (horaInicial<horaFinal){
        printf("%d\n", horaFinal-horaInicial);
    }
    else{
        printf("1440\n");
    }
}

int main(){

    int horaI,minutoI,horaF,minutoF;
    scanf("%d:%d %d:%d",&horaI,&minutoI,&horaF,&minutoF);

    calcular_tempo(horaI,minutoI,horaF,minutoF);

    system("PAUSE");
    return 0;
}
