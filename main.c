#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.c"

void printArray(int arr[], int n) {
    int i;
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n = 1000;
    int *vetor = malloc(n * sizeof(int)); 
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    FILE *file = fopen("numeros_invertidos.txt", "r");
    for (int i = 0; i < n && fscanf(file, "%d", &vetor[i]) != EOF; i++);
    fclose(file);

    clock_t start, end;
    double cpu_time_used;

    // Bubble Sort
    start = clock();
    int numComparisons = 0;
    int numSwaps = 0;
    bubbleSort(vetor, n, &numComparisons, &numSwaps);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Bubble Sort: %f segundos\n", cpu_time_used);
    printf("Numero de comparacoes: %d\n", numComparisons);
    printf("Numero de trocas: %d\n", numSwaps);
    printf("Numeros ordenados pelo Bubble Sort:\n");
    printf("%d ", vetor[0] - 999000);  // Imprime o primeiro número
    for (int i = 1; i < n-1; i++) {
        if (i < 10 || i > n - 10)  // Imprime os 10 primeiros e 10 últimos números
            printf("%d ", vetor[i] - 999000);
        else if (i == 10)  // Adiciona ... no meio para indicar números omitidos
            printf("... ");
    }
    printf("%d\n", vetor[n-1] - 999000); // Imprime o último número
    printf("\n");

    // Redefinir vetor
    file = fopen("numeros_invertidos.txt", "r");
    for (int i = 0; i < n && fscanf(file, "%d", &vetor[i]) != EOF; i++);
    fclose(file);

    // Insertion Sort
    start = clock();
    numComparisons = 0;
    numSwaps = 0;
    insertionSort(vetor, n, &numComparisons, &numSwaps);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Insertion Sort: %f segundos\n", cpu_time_used);
    printf("Numero de comparacoes: %d\n", numComparisons);
    printf("Numero de trocas: %d\n", numSwaps);
    printf("Numeros ordenados pelo Insertion Sort:\n");
    printf("%d ", vetor[0] - 999000); 
    for (int i = 1; i < n-1; i++) {
        if (i < 10 || i > n - 10)  
            printf("%d ", vetor[i] - 999000);
        else if (i == 10)  
            printf("... ");
    }
    printf("%d\n", vetor[n-1] - 999000);
    printf("\n");

    // Redefinir vetor
    file = fopen("numeros_invertidos.txt", "r");
    for (int i = 0; i < n && fscanf(file, "%d", &vetor[i]) != EOF; i++);
    fclose(file);

    // Selection Sort
    start = clock();
    numComparisons = 0;
    numSwaps = 0;
    selectionSort(vetor, n, &numComparisons, &numSwaps);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Selection Sort: %f segundos\n", cpu_time_used);
    printf("Numero de comparacoes: %d\n", numComparisons);
    printf("Numero de trocas: %d\n", numSwaps);
    printf("Numeros ordenados pelo Selection Sort:\n");
    printf("%d ", vetor[0] - 999000);  
    for (int i = 1; i < n-1; i++) {
        if (i < 10 || i > n - 10) 
            printf("%d ", vetor[i] - 999000);
        else if (i == 10)  
            printf("... ");
    }
    printf("%d\n", vetor[n-1] - 999000);
    printf("\n");

    // Redefinir vetor
    file = fopen("numeros_invertidos.txt", "r");
    for (int i = 0; i < n && fscanf(file, "%d", &vetor[i]) != EOF; i++);
    fclose(file);

    // Merge Sort
    start = clock();
    mergeSort(vetor, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Merge Sort: %f segundos\n", cpu_time_used);
    printf("Numeros ordenados pelo Merge Sort:\n");
    printf("%d ", vetor[0] - 999000); 
    for (int i = 1; i < n-1; i++) {
        if (i < 10 || i > n - 10)  
            printf("%d ", vetor[i] - 999000);
        else if (i == 10)  
            printf("... ");
    }
    printf("%d\n", vetor[n-1] - 999000);
    printf("\n");

    // Redefinir vetor
    file = fopen("numeros_invertidos.txt", "r");
    for (int i = 0; i < n && fscanf(file, "%d", &vetor[i]) != EOF; i++);
    fclose(file);

    // Quick Sort
    start = clock();
    quickSort(vetor, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Quick Sort: %f segundos\n", cpu_time_used);
    printf("Numeros ordenados pelo Quick Sort:\n");
    printf("%d ", vetor[0] - 999000);  
    for (int i = 1; i < n-1; i++) {
        if (i < 10 || i > n - 10) 
            printf("%d ", vetor[i] - 999000);
        else if (i == 10)  
            printf("... ");
    }
    printf("%d\n", vetor[n-1] - 999000);
    printf("\n");

    // Redefinir vetor
    file = fopen("numeros_invertidos.txt", "r");
    for (int i = 0; i < n && fscanf(file, "%d", &vetor[i]) != EOF; i++);
    fclose(file);

    // Heap Sort
    start = clock();
    heapSort(vetor, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Heap Sort: %f segundos\n", cpu_time_used);
    printf("Numeros ordenados pelo Heap Sort:\n");
    printf("%d ", vetor[0] - 999000); 
    for (int i = 1; i < n-1; i++) {
        if (i < 10 || i > n - 10)  
            printf("%d ", vetor[i] - 999000);
        else if (i == 10)  
            printf("... ");
    }
    printf("%d\n", vetor[n-1] - 999000);
    printf("\n");
    printf("Pressione ENTER para sair.\n");
    free(vetor);
    getchar();
    return 0;
}
