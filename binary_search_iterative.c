// Binary Search implemantation using c language
#include <stdio.h>


void bubble_sort(int A[], int n) {
    int i, j, t;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-i-1; j++){
            if (A[j] > A[j+1]) {
                t = A[j+1];
                A[j+1] = A[j];
                A[j] = t;
            }
        }
    }
}

int binary_search(int A[], int n, int data) {
    int low = 0, mid, high = n;
    while (low <= high) {
        mid = low + (high-low) / 2;
        if (A[mid] == data) {
            return mid;
        }
        if (A[mid] < data) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return -1;
}
int main() {
    int A[] = {3, 5, 6, 1, 32, 2, 4, 56, 19, 10, 9, 7, 8};
    int i, n = 13;
    bubble_sort(A, n);
    
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    int a, b;
    printf("\nEnter a number for search: ");
    scanf("%d", &a);
    b = binary_search(A, n, a);
    printf("\nNumber index is: %d\n", b);

    return 0;
}