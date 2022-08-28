#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compara (int *vector1,int *vector2){
    int index,count=0;
    if (sizeof(vector1)==sizeof(vector2)){
        for (index=0;index<sizeof(vector1);index++){
            if (vector1[index]==vector2[index]){
                count++;
                if (count==sizeof(vector1)){
                    return 1;
                }
            }
        }
    }
    else{
        return 0;
    }
}

void fill(int *ptrv,int n){

    int index;
    for (index=0;index<=n;index++){
        ptrv[index]=rand()%100;
    }
    for (index=0;index<=n;index++){
        printf("%2d\n",ptrv[index]);
    }
}

void main(){

    srand (time(0));
    int N,M,index;
    printf("Choose vector1 size: ");
    scanf("%d",&N);
    getchar();
    printf("Choose vector2 size: ");
    scanf("%d",&M);
    int vector1[N],vector2[M];

    fill(vector1,N);
    printf("\n\n");
    fill(vector2,M);

    if(compara(vector1,vector2)==1){
        printf("The vectors are equals.\n");
    }
    else{
        printf("The vectors are not equals.\n");
    }

}
