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

int retornaProximoPrimo(int n){
    while(1){
        if(primo(n+1)){
            return n+1;
        }
    n++;
    }
}

int main(){

    int num;

    scanf("%d",&num);

    printf("%d\n",retornaProximoPrimo(num));

    system("PAUSE");
    return 0;
}
