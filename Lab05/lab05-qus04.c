

#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};
struct node *front=NULL, *rear=NULL;


struct node1{
int data1;
struct node *next1;
};
struct node *front1=NULL, *rear1=NULL;


void copy(){
    struct node *temp=front;
        if(front==NULL)
        printf("\nQueue is Empty\n");
        else {
                front1=temp;

        while(temp!=NULL)
        {
          // rear1->next=temp;
         //  rear=temp;
           temp=temp->next;
        }
         rear1=temp;
         free(temp);

        }

 printf("Successfully copied queue 1 to queue 2\n");
}

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

void display1(){

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

void display2(){

    struct node1 *temp=front1;

    if(front==NULL)
        printf("\nQueue is empty!!!!\n");

    else {

        while(temp)
        {
            printf("%d-->",temp->data1);
            temp=temp->next1;
        }

        printf("NULL\n");
        }
}

int main(){
    int choice=0;
    while(choice!=4){
    printf("\n  -----MENU-----\n   1-Enter element in queue(1),\n   2-display,\n   3-copy queue(1) to queue(2) ,\n   4-exit \n Enter your choice: \n");
    scanf("%d",&choice);

    switch(choice){

    case 1:
        enqueue();
        break;
    case 2:
     printf("You have chosen display operation:\n");
                int num;
                 printf("\n 1-queue \n 2-queue \n enter choice: ");
                 scanf("%d",&num);

                while(num>2||num<1){
                 printf("\n 1-queue \n 2-queue \n enter choice: ");
                 scanf("%d",&num);
                }
                if(num==1) display1();
                else if(num==2)display2();
         break;
    case 3:
         printf("You have chosen copy operation:\n");
        copy();
        break;
    case 4:
        break;
    default:
        printf("Wrong choice: try another\n");
    }

    }
    return 0;
}
