#include<stdio.h>
int TOWER(int N, char A, char B, char C){

    if(N==1)
    {
        printf("\n %d disc is moving from %c to %c \n",N,A,C);
    }

    else {

        TOWER(N-1, A,C,B);
        printf("\n %d disc is moving from %c to %c \n",N,A,C);
        TOWER(N-1, B,A,C);

    }
}


int main(){

    int N;
    printf("How many disc:");
    scanf("%d",&N);

    TOWER(N,'a','b','c');


return 0;
}
