#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int medianOfThree(int a, int b, int c) {
    if ((a - b) * (c - a) >= 0)
        return a;
    else if ((b - a) * (c - b) >= 0)
        return b;
    else
        return c;
}

int medianOfMedians(int arr[], int n) {
    if (n <= 5) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        return arr[n / 2];
    } else {
        int numGroups = (n + 4) / 5;
        int *medians = (int *)malloc(numGroups * sizeof(int));
        for (int i = 0; i < numGroups; i++) {
            int groupSize = (i == numGroups - 1) ? (n % 5 == 0 ? 5 : n % 5) : 5;
            int *group = (int *)malloc(groupSize * sizeof(int));
            for (int j = 0; j < groupSize; j++) {
                group[j] = arr[i * 5 + j];
            }
            medians[i] = medianOfMedians(group, groupSize);
            free(group);
        }

        int median = medianOfMedians(medians, numGroups);
        free(medians);
        return median;
    }
}

int kthSmallest(int arr[], int left, int right, int k) {
    if (k > 0 && k <= right - left + 1) {
        int median = medianOfMedians(arr + left, right - left + 1);

        int i;
        for (i = left; i <= right; i++) {
            if (arr[i] == median)
                break;
        }
        swap(&arr[i], &arr[right]);

        i = left;
        for (int j = left; j <= right - 1; j++) {
            if (arr[j] <= median) {
                swap(&arr[i], &arr[j]);
                i++;
            }
        }
        swap(&arr[i], &arr[right]);

        if (i - left == k - 1)
            return arr[i];
        else if (i - left > k - 1)
            return kthSmallest(arr, left, i - 1, k);
        else
            return kthSmallest(arr, i + 1, right, k - i + left - 1);
    }
    return -1;
}

int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; 

    int kth = kthSmallest(arr, 0, n - 1, k);
    if (kth != -1)
        printf("O %d-ésimo menor elemento é %d\n", k, kth);
    else
        printf("Não há %d elementos no array\n", k);

    return 0;
}
