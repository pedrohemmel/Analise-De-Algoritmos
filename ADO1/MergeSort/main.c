#include <stdio.h>
#include <stdlib.h>

#define N 5

void printVector(int vector[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}


void sort(int vector[], int left, int middle, int right, int n) {
    int helper[n];
    for (int i = left; i <= right; i++) {
        helper[i] = vector[i];
    }

    int i = left;
    int j = middle + 1;
    int k = left;
    while (i <= middle && j <= right) {
        
        if (helper[i] <= helper[j]) {
            vector[k] = helper[i];
            i++;
        } else {
            vector[k] = helper[j];
            j++;
        }
        k++;    
        
    }
    while (i <= middle) {
        vector[k] = helper[i];
        i++;
        k++;
    }

    printVector(vector, n);
}

int main() {
    int vector[N] = {3, 2, 6, 1, 10};
    sort(vector, 0, (N - 1) / 2, N - 1, N);
    return  0;
}
