#include <stdio.h>
#include <stdlib.h>

void insertionSort(float *bucket, int n) {
    for (int i = 1; i < n; ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    float **buckets = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
    }
    for (int i = 0; i < n; i++) {
        int bi = (int)(n * arr[i]);
        buckets[bi][i] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], n);
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (buckets[i][j] != 0) {
                arr[index++] = buckets[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    float arr[] = {0.897f, 0.565f, 0.656f, 0.1234f, 0.665f, 0.3434f};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}
