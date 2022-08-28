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

int somaPrimos(int N){
    int i=1,sum=0;
    for (i;i<=N;i++){
        if(primo(i)){
            sum=sum+i;
        }
    }
    return sum;
}

int main(){
    int quantidade;
    scanf("%d",&quantidade);

    printf("%d\n",somaPrimos(quantidade));
}
