#include <stdio.h>
#include <stdlib.h>

int primo(int n){
    int count=0,i;
    for(i=1;i<=n;i++){
        if(n%i==0){
            count++;
        }
    }
    if (count==2){
        return 1;
    }
    else{
        return 0;
    }
}

int divisaoSimultanea(int x,int y){
    int i=1;
    int mult=1;
    while(x!=1 || y!=1){
        if(primo(i)){
            if(x%i==0 || y%i==0){
                if(x%i == 0){
                    x=x/i;
                }
                if(y%i == 0){
                    y=y/i;
                }
                mult=mult*i;
            }
            else if (x%i!=0 && y%i!=0){
                i++;
            }
        }
        else{
            i++;
        }
    }
    return mult;

}

int main(){

    int num1,num2;
    scanf("%d %d",&num1,&num2);

    printf("%d\n",divisaoSimultanea(num1,num2));

    system("PAUSE");
    return 0;
}
