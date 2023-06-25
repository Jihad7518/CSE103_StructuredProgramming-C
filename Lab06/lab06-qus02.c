#include<stdio.h>

int Fibonacci(int N){
 if(N==0 || N==1)
    return N;

 else
    return Fibonacci(N-1)+Fibonacci(N-2);


}

int main(){
int n;
printf("Enter your number: ");
scanf("%d",&n);
int sum=Fibonacci(n);
printf("%dth Fibonacci number is : %d",n,sum);

return 0;
}

