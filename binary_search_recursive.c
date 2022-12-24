// Binary search implemantation using c language

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

int binary_search(int A[], int low, int high, int data) {
    int mid = low+(high-low)/ 2;
    if (low > high){
        return -1;
    }
    if(A[mid] == data) {
        return mid;
    }
    if (A[mid] < data) {
        return binary_search(A, mid+1, high, data);
    }
    else {
        return binary_search(A, low, mid-1, data);
    }
    return -1;
}

int main() {
    int A[] = {3, 5, 10, 33, 1, 34, 56, 83, 103, 48};
    int i, n = 10, a, b;
    selection_sort(A, n);
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\nEnter a number: ");
    scanf("%d", &a);
    b = binary_search(A, 0, n, a);
    printf("\nNumber index is: %d\n", b);

    return 0;
}