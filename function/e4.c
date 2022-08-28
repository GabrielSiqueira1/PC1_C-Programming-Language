#include <stdio.h>
#include <stdlib.h>

int somatorio(int n){
    int sum=0,i;
    for (i=3;i<=n;i++){
        sum=sum+(5*i+2);
    }
    return sum;
}

int main(){
    int num;
    scanf("%d",&num);
    printf("%d\n",somatorio(num));
    system("PAUSE");
    return 0;
}
