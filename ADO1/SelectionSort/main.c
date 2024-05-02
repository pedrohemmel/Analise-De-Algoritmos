#include <stdio.h>
#include <stdlib.h>

#define N 5

void printVector(int vector[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void sort(int vector[], int n) {
    int i, j, min;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++) 
            if (vector[j] < vector[min]) {
                min = j;
            }
            if(min != i) {
                int aux = vector[min];
                vector[min] = vector[i];
                vector[i] = aux;
            }
    }
    printVector(vector, n);
}

int main() {
    int vector[N] = {3, 2, 6, 1, 10};
    sort(vector, N);
    return  0;
}