#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

void imprimirMatriz(int matriz[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiplicarMatrices(int matrizA[SIZE][SIZE], int matrizB[SIZE][SIZE], int resultado[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

int main() {
    int matrizA[SIZE][SIZE];
    int matrizB[SIZE][SIZE];
    int resultado[SIZE][SIZE];

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrizA[i][j] = rand() % 10;
            matrizB[i][j] = rand() % 10;
        }
    }

    printf("Matriz A:\n");
    imprimirMatriz(matrizA);

    printf("Matriz B:\n");
    imprimirMatriz(matrizB);

    clock_t inicio = clock();

    multiplicarMatrices(matrizA, matrizB, resultado);

    clock_t fin = clock();

    double tiempo_transcurrido = ((double)(fin - inicio)) / CLOCKS_PER_SEC * 1000.0;

    printf("Resultado de la multiplicacion:\n");
    imprimirMatriz(resultado);

    printf("Tiempo de ejecucion: %.2f milisegundos\n", tiempo_transcurrido);

    return 0;
}

