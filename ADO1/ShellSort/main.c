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
    int gap = 1;
    while (gap < n) {
        gap = 3 * gap + 1;
    }
    while (gap > 0) {
        for (int i = gap; i < n; i += gap) {
            int j = i;
            int tmp = vector[i];
            while ((j >= gap) && (tmp < vector[j - gap])) {
                vector[j] = vector[j - gap];
                j -= gap;
            }
 
            vector[j] = tmp;
        }
        gap /= 3;
    }

    printVector(vector, n);
}

int main() {
    int vector[N] = {3, 2, 6, 1, 10};
    sort(vector, N);
    return  0;
}