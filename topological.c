#include <stdio.h>
#include <stdlib.h>

// Topological sorting done by source removal algorithm
void topologicalSorting(int arr[10][10], int n) {
    // in[] is the input array that keep the count of sources for each node,
    // out[] is the output array, s[] is the stack
    int in[n], out[n], s[n], top = -1;
    int i, j, k = 0;

    // Initializing the in-degree array
    for (i = 0; i < n; i++) {
        in[i] = 0;
        for (j = 0; j < n; j++) {
            if (arr[j][i] == 1)
                in[i]++;
        }
    }

    while (1) {
        // Adding vertices with no incoming edges to the stack
        for (i = 0; i < n; i++) {
            if (in[i] == 0) {
                s[++top] = i;
                in[i] = -1; // Mark as visited
            }
        }

        // If no vertices with 0 in-degree are found and stack is empty, exit loop
        if (top == -1)
            break;

        // Popping the top element of the stack
        out[k] = s[top--];

        // Decrementing in-degrees of connected vertices
        for (i = 0; i < n; i++) {
            if (arr[out[k]][i] == 1) {
                in[i]--;
            }
        }

        // Incrementing the index for the output array
        k++;
    }

    printf("Topological sorting order is\n");
    for (i = 0; i < n; i++)
        printf("%d ", out[i] + 1);
}

int main() {
    int n;
    printf("Enter the number of vertices in graph: ");
    scanf("%d", &n);

    int arr[10][10];

    printf("Enter the adjacency matrix for the graph\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    topologicalSorting(arr, n);
    return 0;
}
