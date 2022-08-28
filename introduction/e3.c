#include <stdio.h>

main(){
    int A,B,suport;
    A=5;
    B=3;
    suport=A;
    A=B;
    B=suport;
    printf("%d %d",A,B);
}
