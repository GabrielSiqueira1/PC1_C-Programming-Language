#include <stdio.h>
#include <stdlib.h>

int bissexto(int ano){
    if((ano%100!=0 && ano%4==0) || (ano%100==0 && ano%400==0))
        return 1;
    else
        return 0;
}

int data(int dia,int mes,int ano){
    int dias,i;
    dias=0;
    if (bissexto(ano)){
        for (i=1;i<=mes;i++){
            if(i%2!=0){
                if(i!=mes){
                    dias=dias+31;
                }
                else{
                    dias=dias+dia;
                }
            }
            else if(i==2){
                if(i!=mes){
                    dias=dias+29;
                }
                else{
                    dias=dias+dia;
                }
            }
            else{
                if(i!=mes){
                    dias=dias+30;
                }
                else{
                    dias=dias+dia;
                }
            }
        }
        return dias;
    }
    else{
        for (i=1;i<=mes;i++){
            if(i%2!=0){
                if(i=!mes){
                    dias=dias+31;
                }
                else{
                    dias=dias+dia;
                }
            }
            else if(i==2){
                if(i!=mes){
                    dias=dias+28;
                }
                else{
                    dias=dias+dia;
                }
            }
            else{
                if(i=!mes){
                    dias=dias+30;
                }
                else{
                    dias=dias+dia;
                }
            }
        }
        return dias;
    }
}

int main(){

    int dia,mes,ano;
    scanf("%d %d %d",&dia,&mes,&ano);

    printf("%d\n",data(dia,mes,ano));

    system("PAUSE");
    return 0;
}
