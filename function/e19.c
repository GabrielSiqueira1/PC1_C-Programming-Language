#include <stdio.h>
#include <stdlib.h>

int multiplos(int n){
    int i=1,count=0,mult;
    while(1){
        count=0;
        mult=n*i;
        if(mult/10==0){
            if(mult%10!=1 && mult%10!=2 && mult%10!=0){
                    i++;
                }
            else{
                return n*i;
            }
        }
        else{
            while(mult/10!=0){
                if(mult%10!=1 && mult%10!=2 && mult%10!=0){
                    count++;
                }
                mult=mult/10;
                if(mult%10!=1 && mult%10!=2 && mult%10!=0){
                    count++;
                }
            }
            if(count==0){
                return n*i;
            }
            i++;
        }
    }
}

void somatorio(){
    float sum=0;
    int i;
    for (i=1;i<=100;i++){
        sum=sum+(multiplos(i)/(float)i);
    }
    printf("%0.f\n",sum);
}

int main(){

    somatorio();

    system("PAUSE");
    return 0;
}

