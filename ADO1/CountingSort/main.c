#include <stdio.h>
#include <stdlib.h>

void printVector(int vector[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void sort(int vector[], int k, int n) {
    int *vector1 = (int *)malloc(n * sizeof(int));  
    int *vector2 = (int *)calloc((k + 1), sizeof(int));

    if (vector1 == NULL || vector2 == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    for (int j = 0; j < n; j++) {
        vector2[vector[j]]++;
    }

    for (int i = 1; i <= k; i++) {
        vector2[i] += vector2[i - 1];
    }

    for (int j = n - 1; j >= 0; j--) {
        vector1[vector2[vector[j]] - 1] = vector[j];
        vector2[vector[j]]--;
    }

    printVector(vector1, n);

    free(vector1);
    free(vector2);
}

int main() {
    int vector[] = {3, 2, 6, 1, 10};
    int k = 10;
    int n = sizeof(vector) / sizeof(vector[0]);
    sort(vector, k, n);
    return 0;
}
