#include <stdio.h>

main()
{
    float litros, valor_min, quant_agua, conta_agua, desconto;
    litros=1000.0;
    scanf("%f %f", &valor_min,&quant_agua);
    conta_agua=(0.02*valor_min*quant_agua)/litros;
    desconto=conta_agua*0.85;
    printf("%f\n", conta_agua);
    printf("%f", desconto);
}
