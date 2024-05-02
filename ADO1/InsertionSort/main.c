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
    for(int i = 1; i < n; i++) {
        int j = i; 
        while(j > 0 && vector[j] < vector[j - 1]) {
            int aux = vector[j];
            vector[j] = vector[j - 1];
            vector[j - 1] = aux;
            j--;
        }
    }

    printVector(vector, n);
}

int main() {
    int vector[N] = {3, 2, 6, 1, 10};
    sort(vector, N);
    return  0;
}