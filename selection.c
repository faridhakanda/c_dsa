// Selection sort using c language
#include <stdio.h>

void selection_sort(int A[], int n) {
    int i, j, t, index;
    for (i = 0; i < n; i++) {
        index = i;
        for (j = i+1; j < n; j++) {
            if (A[j] < A[index]) {
                index = j;
            }
        }
        if (index != i) {
            t = A[i];
            A[i] = A[index];
            A[index] = t;
        }
    }
}

int main() {
    int A[] = {3, 10, 39, 31, 2, 1, 4, 56, 18, 8, 19};
    int i, n = 11;
    selection_sort(A, n);
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    
    return 0;
}