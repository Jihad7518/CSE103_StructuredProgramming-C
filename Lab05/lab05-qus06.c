#include <stdio.h>
#include <stdlib.h>

void push1(int);
void push2(int);
int pop1();
int pop2();
void enqueue();
void dequeue();
void display();
void create();

int st1[100], st2[100];
int top1 = -1, top2 = -1;
int count = 0;

void main()
{
    int ch;

    create();
    while (1)
    {

    printf("\n  -----MENU-----\n   1-enqueue,\n   2-dequeue,\n   3-display,\n   4-exit \n Enter your choice: \n");
        scanf("%d", &ch);
        switch (ch)
        {
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
            printf("Exiting..... ....\n");
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}

/*Function to create a queue*/
void create()
{
    top1 = top2 = -1;
}

/*Function to push the element on to the stack*/
void push1(int data)
{
    st1[++top1] = data;
}

/*Function to pop the element from the stack*/
int pop1()
{
    return(st1[top1--]);
}

/*Function to push an element on to stack*/
void push2(int data)
{
    st2[++top2] = data;
}

/*Function to pop an element from th stack*/

int pop2()
{
    return(st2[top2--]);
}

/*Function to add an element into the queue using stack*/
void enqueue()
{
    int data, i;

    printf("Enter data into queue:  ");
    scanf("%d", &data);
    push1(data);
    printf("Successfully enqueued");
    count++;
}

/*Function to delete an element from the queue using stack*/

void dequeue()
{
    int i;

    for (i = 0;i <= count;i++)
    {
        push2(pop1());
    }
    pop2();
    count--;
    for (i = 0;i <= count;i++)
    {
        push1(pop2());
    }
    printf("Successfully dequeued");
}

/*Function to display the elements in the stack*/

void display()
{
    int i;

    for (i = 0;i <= top1;i++)
    {
        printf("%d-->", st1[i]);
    }
     printf("NULL\n");
}
