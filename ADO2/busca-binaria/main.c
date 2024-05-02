#include <stdlib.h>
#include <stdio.h>

int binary_search(int vector[10],int vector_size, int item);

int main() {
    int vector[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", binary_search(vector, 10, 5));
    return 0;
}

int binary_search(int vector[10],int vector_size, int item) {
    int begin = 0;
    int end = vector_size - 1;

    while(begin <= end) {
        int i = (begin + end) / 2;

        if(vector[i] > item) {
            end = i;
        } else if(vector[i] < item) {
            begin = i + 1;
        } else {
            return i;
        }
    }
    return -1;
}