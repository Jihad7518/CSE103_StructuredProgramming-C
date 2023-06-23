
#include<stdio.h>
#include<stdlib.h>

struct node{

int data;
struct node *next;

};

struct node *front=NULL, *rear=NULL;

void enqueue(){

    struct node *newNode=(struct node*)malloc(sizeof(struct node));

    int item;
    printf("\n Enter your data:");
    scanf("%d",&item);

    newNode->data=item;
    newNode->next=NULL;

    if(front==NULL && rear==NULL)
        front=rear=newNode;
    else {

        rear->next=newNode;
        rear=newNode;


    }


}

void dequeue(){

    if(front==NULL)
        printf("\nQueue is Empty\n");

    else {

        struct node *temp=front;
        printf("%d was deleted from queue\n", temp->data);
        front=front->next;

        if(front==NULL)
            rear=NULL;

        free(temp);

    }


}

void display(){

    struct node *temp=front;

    if(front==NULL)
        printf("\nQueue is empty!!!!\n");

    else {

        while(temp)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }

        printf("NULL\n");
        }




}

int main(){
    int choice;
    while(1){
    printf("\n  -----MENU-----\n   1-enqueue,\n   2-dequeue,\n   3-display,\n   4-exit \n Enter your choice: \n");
    scanf("%d",&choice);

    switch(choice){

    case 1:
        printf("You have chosen enqueue operation:\n");
        enqueue();
        break;
    case 2:
         printf("You have chosen dequeue operation:\n");
         dequeue();
        break;
    case 3:
     printf("You have chosen display operation:\n");
     display();
        break;
    case 4:
        exit(0);
    default:
        printf("Wrong choice: try another\n");
    }

    }
    return 0;
}
