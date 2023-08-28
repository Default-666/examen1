#include <stdio.h>

int main() {
    double valor_quetzales;
    double valor_sin_iva, monto_iva;

    printf("Ingrese el valor en quetzales: ");
    scanf("%lf", &valor_quetzales);

    valor_sin_iva = valor_quetzales / 1.12; // Calcula el valor sin IVA
    monto_iva = valor_quetzales - valor_sin_iva; // Calcula el monto del IVA

    printf("\nResultados:\n");
    printf("Valor sin IVA: %.2f quetzales\n", valor_sin_iva);
    printf("Monto del IVA (12%%): %.2f quetzales\n", monto_iva);

    return 0;
}
