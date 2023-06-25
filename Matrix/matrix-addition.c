#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{

    int a[10][10], b[10][10], sum[10][10];
    int R, C, i, j;

    printf("Enter Row Number: ");
    scanf("%d", &R);

    printf("Enter Column Number: ");
    scanf("%d", &C);

    //enter first matrix value
    printf("Enter first Matrix of row=%d, col=%d \n", R, C);
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            scanf("%d", &a[i][j]);
        }
    }

    //enter sceond matrix value
    printf("Enter Second Matrix of row=%d, col=%d \n", R, C);
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            scanf("%d", &b[i][j]);
        }
    }

    //now addition
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    //printing result
    printf("The Addition Result of Those two Matrix is: \n");
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
