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

int main(){
    int num;

    scanf("%d",&num);

    if(primo(num)){
        printf("E primo\n");
    }
    else{
        printf("Nao e primo\n");
    }

    system("PAUSE");
    return 0;
}
