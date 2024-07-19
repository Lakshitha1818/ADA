#include <stdio.h>

void merge(int A[100], int low, int mid, int high) {
    int B[100];
    int i = low;
    int k = low;
    int j = mid + 1;
    while (i <= mid && j <= high) {
        if (A[i] <= A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        B[k] = A[i];
        k++; i++;
    }
    while (j <= high) {
        B[k] = A[j]; k++; j++;
    }
    for (i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

void mergesort(int A[100], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

void print(int A[100], int n) {
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
    printf("Before Merged array:\n");
    print(A, n);
    mergesort(A, 0, n - 1);
    printf("Merged array:\n");
    print(A, n);
    return 0;
}
