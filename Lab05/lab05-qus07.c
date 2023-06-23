
#include<stdio.h>
#include<stdlib.h>

struct node{
char data;
struct node *next;

};

struct node *front=NULL, *rear=NULL;



void enqueue(int item){

    struct node *newNode=(struct node*)malloc(sizeof(struct node));

    newNode->data=item;
    newNode->next=NULL;

    if(front==NULL && rear==NULL)
        front=rear=newNode;
    else {

        rear->next=newNode;
        rear=newNode;
    }
}

void display(){

    struct node *temp=front;

    if(front==NULL)
        printf("\nQueue is empty!!!!\n");

    else {

        while(temp)
        {
            printf("%d--> ",temp->data);
            temp=temp->next;
        }

        printf("NULL\n");
        }




}

int main(){
       int n;
    int item;
    printf("Enter number of values: ");
    scanf("%d", &n);
    printf("\n Enter %d elements: ",n);
    for(int i = 0; i < n; i++)
    {
    scanf("%d",&item);

        if(item >= 0)
        {
            enqueue(item);
        }
    }
    display();
    return 0;
}
