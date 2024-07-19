#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void heapify(int arr[100], int n, int i) {
    int max, left, right, temp;
    max = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && arr[left] > arr[max]) {
        max = left;
    }
    if (right < n && arr[right] > arr[max]) {
        max = right;
    }
    if (max != i) {
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;

        heapify(arr, n, max);
    }
}

void heapsort(int arr[100], int n) {
    int temp, i;
    for (i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void print(int arr[100], int n) {
    printf("The array elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main() {
    int n;
    clock_t start_clock,end_clock;
    double time_taken;
    printf("Enter the value of n:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Before sorting:\n");
    print(arr, n);
    start_clock=clock();
    heapsort(arr, n);
    end_clock=clock();
    time_taken=((double)(end_clock-start_clock))/CLOCKS_PER_SEC;
    printf("After sorting:\n");
    print(arr, n);
    printf("%f is the time taken",time_taken);
}
