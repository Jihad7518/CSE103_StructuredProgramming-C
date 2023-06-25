#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10][10], b[10][10], multi[10][10];
    int i, j, k, sum=0, m, n, r, p;

    printf("Enter the row and column of first matrix: ");
    scanf("%d %d", &m, &n);

    printf("Enter the row and column of second matrix: ");
    scanf("%d %d", &r, &p);

    if(n != r){
        printf("Matrix Multipication is not possible");
    }
    else{
        printf("\n Enter the values of first Matrix: \n");
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                scanf("%d", &a[i][j]);
            }
        }

        printf("\n Enter the values of second Matrix: \n");
        for(i=0; i<r; i++){
            for(j=0; j<p; j++){
                scanf("%d", &b[i][j]);
            }
        }
        for(i=0; i<m; i++){
            for(j=0; j<r; j++){
                multi[i][j];
            }
        }
        for(i=0; i<m; i++){
            for(j=0; j<p; j++){
                sum=0;
                for(k=0; k<n; k++){
                    sum = sum+a[i][k]*b[k][j];
                }
                multi[i][j]= sum;
            }
        }
    }

    printf("Multipication of two matrix: \n");
    for(i=0; i<m; i++){
        printf("\n");
        for(j=0; j<p; j++){
            printf("%d\t", multi[i][j]);
        }
    }

    return 0;
}
