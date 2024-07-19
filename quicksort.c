#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[100], int lb, int ub) {
    int i = lb;
    int j = ub;
    int pivot = A[lb];
    while (i < j) {
        while (A[i] <= pivot && i < ub) {
            i++;
        }
        while (A[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[lb], &A[j]);
    return j;
}

void quicksort(int A[100], int lb, int ub) {
    if (lb < ub) {
        int S = partition(A, lb, ub);
        quicksort(A, lb, S - 1);
        quicksort(A, S + 1, ub);
    }
}

void print(int A[100], int n) {
    printf("Array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }
}

int main() {
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    int A[100];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printf("Before sorting:\n");
    print(A, n);
    quicksort(A, 0, n - 1);
    printf("After sorting:\n");
    print(A, n);
    return 0;
}
