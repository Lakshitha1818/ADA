#include <stdio.h>
#define inf 999

int min(int a,int b)
{
    return (a<b)?a:b;
}
int main() {

    int n;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    int A[n][n];
    int R[n][n];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
            R[i][j]=A[i][j];
        }
    }

    // Floyd-Warshall algorithm to compute transitive closure
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               R[i][j] =min(R[i][j],R[i][k]+R[k][j]);
            }
        }
    }

    printf("The transitive closure is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                if(R[i][j]==inf)
                {
                    printf("oo");
                }
                else{printf("%d ", R[i][j]);
        }}

        printf("\n");
    }

    return 0;
}

