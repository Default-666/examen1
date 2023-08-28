#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Inicializar la semilla para la generación de números aleatorios

    char continuar;
    int resultado_anterior = 0;

    FILE *archivo = fopen("salida.txt", "a");  // Abrir el archivo en modo append

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;  // Terminar el programa con código de error
    }

    do {
        int dado1 = rand() % 6 + 1;  // Generar números aleatorios entre 1 y 6
        int dado2 = rand() % 6 + 1;
        int suma = dado1 + dado2;

        fprintf(archivo, "Dado 1: %d, Dado 2: %d, Suma: %d\n", dado1, dado2, suma);

        if (suma == 8) {
            printf("¡Ganaste! Suma: %d\n", suma);
            break;
        } else if (suma == 7 && resultado_anterior == 8) {
            printf("Perdiste. Suma: %d\n", suma);
            break;
        } else if (suma == 7) {
            printf("¡Perdiste! Suma: %d\n", suma);
            break;
        }

        printf("Suma: %d. ¿Quieres continuar lanzando? (s/n): ", suma);
        scanf(" %c", &continuar);

        resultado_anterior = suma;
    } while (continuar == 's' || continuar == 'S');

    fclose(archivo);  // Cerrar el archivo

    archivo = fopen("salida.txt", "r");  // Abrir el archivo en modo lectura

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;  // Terminar el programa con código de error
    }

    printf("\nHistorial de lanzamientos:\n");
    char caracter;

    while ((caracter = fgetc(archivo)) != EOF) {
        printf("%c", caracter);
    }

    fclose(archivo);  // Cerrar el archivo de nuevo

    return 0;  // Terminar el programa exitosamente
}
