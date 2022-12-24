// Linear search implemantation using c language

#include <stdio.h>

int linear_search(int A[], int n, int data) {
    int i;
    for (i = 0; i < n; i++) {
        if (A[i] == data) {
            return i;
        }
    }
    return -1;
}

int main() {
    int A[] = {3, 5, 10, 1, 33, 4, 56, 19, 38};
    int i, n = 9, a;
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\nEnter a number: ");
    scanf("%d", &a);
    printf("Number index is: %d\n", linear_search(A, n, a));

    return 0;
}