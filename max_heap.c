// Max heap algorithms using c langauge for implemantation

#include <stdio.h>

int left(int i) {
    return 2*i;
}
int right(int i) {
    return 2*i+1;
}
int parent(int i) {
    return i / 2;
}


void max_heapify(int A[], int size, int i) {
    int l, r, t, largest;
    l = left(i);
    r = right(i);

    if (l <= size && A[l] > A[i]) {
        largest = l;
    } else {
        largest = i;
    }

    if (r <= size && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        t = A[i];
        A[i] = A[largest];
        A[largest] = t;
        max_heapify(A, size, largest);
    }
}

void build_heap(int A[], int size) {
    int i;
    for (i = size / 2; i >= 1; i--) {
        max_heapify(A, size, i);
    }
}

int get_max(int A[]){
    return A[1];
}
int extract_max(int A[], int size) {
    int max;
    if (size < 1) {
        printf("Heap is overflow ");
        return -1;
    }
    max = A[1];
    A[1] = A[size];
    size -= 1;
    max_heapify(A, size, 1);
    return max;
}
int priority_queue(int A[], int size, int a) {
    if (a < A[size]) {
        printf("Node is smaller than current node ");
        return -1;
    }
    int i, p, t;
    i = size;
    A[i] = a;
    while (i > size && A[i] > A[parent(i)]) {
        p = parent(i);
        t = A[p];
        A[p] = A[i];
        A[i] = t;
        i = p;
    }
    i += 1;
    return size;
}

void heap_sort(int A[], int size) {
    int i, t;
    build_heap(A, size);
    for (i = size; i > 1; i--) {
        t = A[1];
        A[1] = A[i];
        A[i] = t;
        size -= 1;
        max_heapify(A, size, 1);
    }
}

int main() {
    int A[] = {0, 100, 39, 8, 19, 28, 3, 1, 34, 58, 29};
    int i, n = 10;
    int max = extract_max(A, n);
    printf("Maximum number of the array: %d\n", max);
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    int in = priority_queue(A, n, a);

    heap_sort(A, n);
    for (i = 0; i <= n; i++) {
        printf("%d ",  A[i]);
    }
    printf("\nSize of the heap: %d\n", in);
    return 0;
}
