#include <stdio.h>  
#define INF 999999 

void fillDistanceMatrix(int n, int A[n][n], int D[n][n]) {  
   for (int i = 0; i < n; i++) {  
       for (int j = 0; j < n; j++) {  
           if (i == j)  
               D[i][j] = 0;  
           else if (A[i][j] == 0)  
               D[i][j] = INF;  
           else  
               D[i][j] = A[i][j];  
       }  
   }  
}  

void floydWarshall(int n, int A[n][n], int D[n][n]) {  
   fillDistanceMatrix(n, A, D);  

   for (int k = 0; k < n; k++) {  
       for (int i = 0; i < n; i++) {  
           for (int j = 0; j < n; j++) {  
               if (D[i][k] < INF && D[k][j] < INF)  
                   if (D[i][k] + D[k][j] < D[i][j])  
                       D[i][j] = D[i][k] + D[k][j];  
           }  
       }  
   }  
}  

int main() {  
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int A[n][n];
    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int D[n][n];  

    floydWarshall(n, A, D);  

    printf("\nShortest distances between all pairs of vertices:\n");  
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {  
            if (D[i][j] == INF)  
                printf("%7s", "INF");  
            else  
                printf("%7d", D[i][j]);  
        }  
        printf("\n");  
    }  

    return 0;  
}
