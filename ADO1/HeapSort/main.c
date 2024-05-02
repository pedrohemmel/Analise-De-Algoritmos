#include <stdio.h>

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

void adjustHeap(int vector[], int n, int i) {
    int bigger = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && vector[left] > vector[bigger])
        bigger = left;

    if (right < n && vector[right] > vector[bigger])
        bigger = right;

    if (bigger != i) {
        swap(&vector[i], &vector[bigger]);
        adjustHeap(vector, n, bigger);
    }
}

void sort(int vector[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        adjustHeap(vector, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&vector[0], &vector[i]);
        adjustHeap(vector, i, 0);
    }

    printVector(vector, n);
}


int main() {
    int vector[N] = {3, 2, 6, 1, 10};
    sort(vector, N);
    return  0;
}
