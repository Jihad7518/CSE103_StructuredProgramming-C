#include <stdio.h>
#include <stdlib.h>
#define MAX 50>


 char q[MAX], f=-1, r=-1;

void eng(char value){
    if(r==MAX-1){
        printf("Queue is full and hence cannot insert");
    }
    else if(f == -1 && r == -1){
        f = r = 0;
    }
    else{
        r = r + 1;
        q[r] = value;
    }

}

char deq(){
    char value;
    if(f == -1){
        printf("Queue is empty, and hence cannot delete");
    }
    else{
        value = q[f];
        if(f == r){
            f = r = -1;
        }
        else{
            f = f+1;
        }
    }
    return value;

}



int main()
{
    int i;
    char s[MAX];
    gets(s);
    for(i = 0 ; s[i] != '\0' ; i++){
        if(s[i]!= ''){
            eng(s[i]);
        }
    }

    for(i = f ; i <= r ; i++){
        s[i] = deq();
        s[i] = '\0';
        puts(s);
    }
}
