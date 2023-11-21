#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main() {
    int arr[SIZE];
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10000;
    }

    clock_t inicio, fin;
    double tiempo[100];

    for (int i = 0; i < 100; i++) {
        int tempArr[SIZE];
        for (int j = 0; j < SIZE; j++) {
            tempArr[j] = arr[j];
        }
        inicio = clock();
        insertionSort(tempArr, SIZE);
        fin = clock();
        tiempo[i] = ((double)(fin - inicio)) / CLOCKS_PER_SEC * 1000.0;
    }

    double promedio = 0, min = tiempo[0], max = tiempo[0];
    for (int i = 0; i < 100; i++) {
        promedio += tiempo[i];
        if (tiempo[i] < min) min = tiempo[i];
        if (tiempo[i] > max) max = tiempo[i];
    }
    promedio /= 100;

    printf("Insertion Sort:\n");
    printf("Tiempo promedio: %.2f ms\n", promedio);
    printf("Tiempo minimo: %.2f ms\n", min);
    printf("Tiempo maximo: %.2f ms\n\n", max);

	for (int i = 0; i < 100; i++) {
	    int tempArr[SIZE];
	    for (int j = 0; j < SIZE; j++) {
	        tempArr[j] = arr[j];
	    }
	    inicio = clock();
	    quickSort(tempArr, 0, SIZE - 1);
	    fin = clock();
	    tiempo[i] = ((double)(fin - inicio)) / CLOCKS_PER_SEC * 1000.0;
	}
	
	double promedio_quick = 0, min_quick = tiempo[0], max_quick = tiempo[0];
	for (int i = 0; i < 100; i++) {
	    promedio_quick += tiempo[i];
	    if (tiempo[i] < min_quick) min_quick = tiempo[i];
	    if (tiempo[i] > max_quick) max_quick = tiempo[i];
	}
	promedio_quick /= 100;
	
	printf("Quick Sort:\n");
	printf("Tiempo promedio: %.2f ms\n", promedio_quick);
	printf("Tiempo minimo: %.2f ms\n", min_quick);
	printf("Tiempo maximo: %.2f ms\n\n", max_quick);

	for (int i = 0; i < 100; i++) {
	    int tempArr[SIZE];
	    for (int j = 0; j < SIZE; j++) {
	        tempArr[j] = arr[j];
	    }
	    inicio = clock();
	    bubbleSort(tempArr, SIZE);
	    fin = clock();
	    tiempo[i] = ((double)(fin - inicio)) / CLOCKS_PER_SEC * 1000.0;
	}
	
	double promedio_bubble = 0, min_bubble = tiempo[0], max_bubble = tiempo[0];
	for (int i = 0; i < 100; i++) {
	    promedio_bubble += tiempo[i];
	    if (tiempo[i] < min_bubble) min_bubble = tiempo[i];
	    if (tiempo[i] > max_bubble) max_bubble = tiempo[i];
	}
	promedio_bubble /= 100;
	
	printf("Bubble Sort:\n");
	printf("Tiempo promedio: %.2f ms\n", promedio_bubble);
	printf("Tiempo minimo: %.2f ms\n", min_bubble);
	printf("Tiempo maximo: %.2f ms\n\n", max_bubble);


    return 0;
}

