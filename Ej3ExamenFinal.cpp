#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50000

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int busquedaSec(int arr[], int n, int obj) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == obj) {
            return i;
        }
    }
    return -1;
}

int busquedaBin(int arr[], int izq, int der, int obj) {
    while (izq <= der) {
        int med = izq + (der - izq) / 2;
        if (arr[med] == obj) {
            return med;
        }
        if (arr[med] < obj) {
            izq = med + 1;
        } else {
            der = med - 1;
        }
    }
    return -1;
}

int main() {
    int arr[SIZE];
    int i, obj, index;
    clock_t inicio, fin;
    double tiempo;

    srand(time(0));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100000;
    }
    bubbleSort(arr, SIZE);

    int ejecNum = 100;
    double vecesSec[ejecNum];
    double vecesBin[ejecNum];

    for (i = 0; i < ejecNum; i++) {
        obj = rand() % 100000;

        inicio = clock();
        index = busquedaSec(arr, SIZE, obj);
        fin = clock();
        tiempo = ((double)(fin - inicio)) * 1000 / CLOCKS_PER_SEC;
        vecesSec[i] = tiempo;

        inicio = clock();
        index = busquedaBin(arr, 0, SIZE - 1, obj);
        fin = clock();
        tiempo = ((double)(fin - inicio)) * 1000 / CLOCKS_PER_SEC;
        vecesBin[i] = tiempo;
    }

    double secSum = 0, binsum = 0;
    double secMin = vecesSec[0], binMin = vecesBin[0];
    double secMax = vecesSec[0], binMax = vecesBin[0];

    for (i = 0; i < ejecNum; i++) {
        secSum += vecesSec[i];
        binsum += vecesBin[i];

        if (vecesSec[i] < secMin) {
            secMin = vecesSec[i];
        }
        if (vecesSec[i] > secMax) {
            secMax = vecesSec[i];
        }

        if (vecesBin[i] < binMin) {
            binMin = vecesBin[i];
        }
        if (vecesBin[i] > binMax) {
            binMax = vecesBin[i];
        }
    }

    double secProm = secSum / ejecNum;
    double binProm = binsum / ejecNum;

    printf("Busqueda Secuencial:\n");
    printf("Min: %.2lf ms\n", secMin);
    printf("Max: %.2lf ms\n", secMax);
    printf("Prom: %.2lf ms\n\n", secProm);

    printf("Busqueda Binaria:\n");
    printf("Min: %.2lf ms\n", binMin);
    printf("Max: %.2lf ms\n", binMax);
    printf("Prom: %.2lf ms\n", binProm);

    return 0;
}

