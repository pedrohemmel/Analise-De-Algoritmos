#include <stdio.h>
#include <stdlib.h>

#define N 5

void printVector(int vector[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int vector[], int left, int right) {
    int pivot = vector[right];  
    int i = (left - 1);  

    for (int j = left; j <= right - 1; j++) {
        if (vector[j] <= pivot) {
            i++;  
            swap(&vector[i], &vector[j]);
        }
    }
    swap(&vector[i + 1], &vector[right]);
    return (i + 1);
}

void sort(int vector[], int left, int right, int n) {
    if (left < right) {
        int pi = partition(vector, left, right);

        sort(vector, left, pi - 1, n);
        sort(vector, pi + 1, right, n);
    }

    printVector(vector, n);
}

int main() {
    int vector[N] = {3, 2, 6, 1, 10};
    sort(vector, 0, N - 1, N);
    return  0;
}

