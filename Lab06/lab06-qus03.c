#include<stdio.h>

int pow(int N, int S){
int sum=0;
 if(S==1){
    sum=N;
    //printf("\n n=%d --sum=%d\n",N,sum);
    return N;
 }

 else {
    sum=N*pow(N,S-1);
    //printf("\n n=%d --sum=%d\n",N,sum);
    return sum;

 }

}

int main(){
int n,s;
int sum;

printf("Enter your number: ");
scanf("%d",&n);

printf("Enter power: ");
scanf("%d",&s);


 if(s==0){
  printf("Output : 1");
  }
  else sum=pow(n,s);

printf("Output : %d",sum);

return 0;
}

