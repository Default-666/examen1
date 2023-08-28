#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ADIVINANZAS 5
#define MAX_NOMBRE 50

typedef struct {
    char adivinanza[100];
    char respuesta[50];
} Adivinanza;

typedef struct {
    char nombre[MAX_NOMBRE];
    int puntuacion;
} Puntuacion;

void jugarAdivinanzas(Adivinanza adivinanzas[], int totalAdivinanzas, Puntuacion *puntuacion) {
    int aciertos = 0;

    printf("\n¡Vamos a jugar adivinanzas!\n");
    for (int i = 0; i < totalAdivinanzas; i++) {
        printf("\nAdivinanza %d:\n", i + 1);
        printf("%s\n", adivinanzas[i].adivinanza);

        char respuestaUsuario[50];
        printf("Ingrese su respuesta: ");
        scanf("%s", respuestaUsuario);

        if (strcmp(respuestaUsuario, adivinanzas[i].respuesta) == 0) {
            printf("¡Correcto!\n");
            aciertos++;
        } else {
            printf("Incorrecto. La respuesta correcta es: %s\n", adivinanzas[i].respuesta);
        }
    }

    puntuacion->puntuacion = aciertos;
    printf("\n¡Juego terminado!\nAciertos: %d\n", aciertos);
}

void verHistorial(Puntuacion puntuaciones[], int totalPuntuaciones) {
    printf("\nHistorial de puntuaciones:\n");
    for (int i = 0; i < totalPuntuaciones; i++) {
        printf("Nombre: %s, Puntuacion: %d\n", puntuaciones[i].nombre, puntuaciones[i].puntuacion);
    }
}

void borrarHistorial(Puntuacion puntuaciones[], int *totalPuntuaciones) {
    *totalPuntuaciones = 0;
    printf("\nHistorial borrado.\n");
}

int main() {
    Adivinanza adivinanzas[MAX_ADIVINANZAS] = {
        {"Blanco por dentro, verde por fuera. Si quieres que te lo diga, espera.", "Pera"},
        {"Aunque te pese no lo puedes ver, aunque lo sigas te va a mantener. ¿Qué es?", "Nariz"},
        // Agrega más adivinanzas aquí
    };

    Puntuacion puntuaciones[100];
    int totalPuntuaciones = 0;

    int opcion;
    char nombre[MAX_NOMBRE];

    printf("Bienvenido a Juego de Adivinanzas\n");

    do {
        printf("\nMenú:\n");
        printf("1. Jugar adivinanzas\n");
        printf("2. Ver historial\n");
        printf("3. Borrar historial\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese su nombre: ");
                scanf("%s", nombre);
                Puntuacion nuevaPuntuacion;
                strcpy(nuevaPuntuacion.nombre, nombre);
                jugarAdivinanzas(adivinanzas, MAX_ADIVINANZAS, &nuevaPuntuacion);
                puntuaciones[totalPuntuaciones++] = nuevaPuntuacion;
                break;
            case 2:
                verHistorial(puntuaciones, totalPuntuaciones);
                break;
            case 3:
                borrarHistorial(puntuaciones, &totalPuntuaciones);
                break;
            case 4:
                printf("¡Hasta luego!\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 4);

    return 0;
}
