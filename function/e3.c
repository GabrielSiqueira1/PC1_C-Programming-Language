#include <stdio.h>
#include <stdlib.h>

int comparacao(int x,int y){
    if (x<y){
        return x;
    }
    else{
        return y;
    }
}

int soma(int comparacaoResultado, int x, int y){
    int sum=0;
    if (comparacaoResultado ==  x){
        for (x;x<=y;x++){
            if(x%2!=0){
                sum=sum+x;
            }
        }
        return sum;
    }
    else{
        for (y;y<=x;y++){
            if(y%2!=0){
                sum=sum+y;
            }
        }
        return sum;
    }

}

int main(){
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    printf("%d\n",comparacao(num1,num2));
    printf("%d\n",soma(comparacao(num1,num2),num1,num2));

    system("PAUSE");
    return 0;
}
