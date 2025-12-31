// Bubble sort implementation using c language
// learning all of data structure and algorithms

#include <stdio.h>

void bubble_sort(int A[], int n) {
    int i, j, t;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (A[j] > A[j+1]) {
                t = A[j+1];
                A[j+1] = A[j];
                A[j] = t;
            }
        }
    }
}

int main() {
    int A[] = {2, 10, 19, 1, 3, 4, 91, 83, 193, 194, 1931, 56, 51};
    int i, n = 13;
    bubble_sort(A, n);
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    
    return 0;
}
