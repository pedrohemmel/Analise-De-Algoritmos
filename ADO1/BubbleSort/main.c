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
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j + 1 < n) {
                if(vector[j] > vector[j + 1]) {
                    int value_to_swap = vector[j];
                    vector[j] = vector[j + 1];
                    vector[j + 1] = value_to_swap;
                }
            }
        }
    }

    printVector(vector, n);
}

int main() {
    int vector[N] = {3, 2, 6, 1, 10};
    sort(vector, N);
    return  0;
}