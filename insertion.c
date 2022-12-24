// Insertion sort algorithms using c language implementation
#include <stdio.h>

void insertion_sort(int A[], int n) {
    int i, j, t;
    for (i = 0; i < n; i++){
        t = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > t) {
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = t;
    }
}

int main() {
    int A[] = {2, 5, 10, 9, 3, 1, 34, 4, 58, 38, 28};
    int i, n = 11;
    insertion_sort(A, n);
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}