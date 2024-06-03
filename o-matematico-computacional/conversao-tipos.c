#include <stdio.h>

int main(){
    int x = 1;
    long y = 2;
    double z;

    // Conversão implícita para double 
    z = 3.5 + x + y;

    // Conversão expícita para int
    x = (int) z/2;

    printf("%d %lf\n", x, z);

    return 0;
}