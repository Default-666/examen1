#include <stdio.h>

int esPrimo(int numero) {
    if (numero <= 1) {
        return 0; // No es primo si es menor o igual a 1
    }

    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0; // No es primo si es divisible por algún número entre 2 y la raíz cuadrada del número
        }
    }

    return 1; // Es primo si no es divisible por ningún número entre 2 y la raíz cuadrada del número
}

int main() {
    int numero;

    printf("Ingrese un número: ");
    scanf("%d", &numero);

    if (esPrimo(numero)) {
        printf("%d es un número primo.\n", numero);
    } else {
        printf("%d es un número compuesto.\n", numero);
    }

    return 0;
}
