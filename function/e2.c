#include <stdio.h>
#include <stdlib.h>

int multiplicacao(int x,int y){
    int sum,i;
    sum=0;
    for(i=1;i<=y;i++){
        sum=sum+x;
    }
    return sum;
}

int main(){
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    printf("%d\n",multiplicacao(num1,num2));

    system("PAUSE");
    return 0;
}
