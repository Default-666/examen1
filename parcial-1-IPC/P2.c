#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VALUES 1000

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int values[MAX_VALUES];
    int n = 0;
    int sum = 0;
    double mean, median, mode, variance, standard_deviation;
    int max_count = 0;

    printf("Ingrese los valores (0 a 100), -1 para terminar:\n");

    while (n < MAX_VALUES) {
        int value;
        scanf("%d", &value);

        if (value == -1) {
            break;
        }

        if (value < 0 || value > 100) {
            printf("Valor fuera de rango. Intente nuevamente.\n");
            continue;
        }

        values[n++] = value;
        sum += value;
    }

    mean = (double)sum / n;

    qsort(values, n, sizeof(int), compare);

    if (n % 2 == 0) {
        median = (values[n / 2 - 1] + values[n / 2]) / 2.0;
    } else {
        median = values[n / 2];
    }

    int current_count = 1;
    int previous_count = 1;

    for (int i = 1; i < n; i++) {
        if (values[i] == values[i - 1]) {
            current_count++;
        } else {
            current_count = 1;
        }

        if (current_count > previous_count) {
            mode = values[i];
            previous_count = current_count;
        }
    }

    variance = 0.0;
    for (int i = 0; i < n; i++) {
        variance += pow(values[i] - mean, 2);
    }
    variance /= n;

    standard_deviation = sqrt(variance);

    int range = values[n - 1] - values[0];

    printf("\nResultados:\n");
    printf("Media: %.2f\n", mean);
    printf("Mediana: %.2f\n", median);
    printf("Moda: %.2f\n", mode);
    printf("Varianza: %.2f\n", variance);
    printf("Desviación Estándar: %.2f\n", standard_deviation);
    printf("Rango: %d\n", range);

    return 0;
}
