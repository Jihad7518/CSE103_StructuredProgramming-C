#include <stdio.h>
#include <stdlib.h>

//structure to store an unit node entity
struct QNode {
        int key;
        struct QNode* next;
};

//structure to store an queue with front and rear pointers
struct Queue {
        struct QNode *front, *rear;
};

//method to create a new node out of given data and insert it to the queue
void enQueue(struct Queue* q, int k)
{
        // Create a new node
        struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
        //assign the given data
        temp->key = k;
        temp->next = NULL;

    //initially when q has no elements, then we should mark first element as both front and rear pointers
        if (q->rear == NULL) {
                q->front = q->rear = temp;
                return;
        }

        // else add it to the rear
        q->rear->next = temp;
        //and adjust the rear pointer
        q->rear = temp;
}

// method to remove a node at front from the queue
void deQueue(struct Queue* q)
{
        // when q has no elements then it is not possible to remove an element from it
        if (q->front == NULL)
                return;

        // get a copy of front node
        struct QNode* temp = q->front;

    //assign front pointer to front's next node
        q->front = q->front->next;


        if (q->front == NULL)
                q->rear = NULL;

    //delete the memory allocated for prev front node of queue
        free(temp);
}

//method to print queuee
void printQueue(struct Queue *q)
{

    //get a copy of q's front
    struct QNode* temp = q->front;

    printf("\n Queue : ");
    //iterate the queue until end
    while(temp != NULL)
    {
        printf("%d ",temp->key);
        temp = temp->next;
    }

    printf("\n");
}

//method to copy one queue's content to another queue
void copyQueue(struct Queue *q1, struct Queue *q2)
{
    //getting q1's front
    struct QNode* temp1 = q1->front;
    struct QNode* temp2 = q2->front;


    //looping the q1
    while(temp1!=NULL)
    {
        //copying content of q1 to q2
        temp2->key = temp1->key;

        //move further in both the queues
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
}

//method to create q out of given staack's data
//here stack is assumed to be given as array with first element being its top of the stack
struct Queue* createQueueFromStack(int *stack)
{
    //create a new queue
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
        q->front = q->rear = NULL;

    //create q from given stack
        for(int i=0;i<5;i++)
        {
            enQueue(q,stack[i]);
        }

        return q;
}

// Driver Program to test anove functions
int main()
{

    //simulation of all the methods


        struct Queue* q1 = (struct Queue*)malloc(sizeof(struct Queue));
        q1->front = q1->rear = NULL;
        enQueue(q1,0);
        enQueue(q1, 1);
        enQueue(q1, 2);
        enQueue(q1, 3);
        enQueue(q1, 4);
        enQueue(q1, 5);
        printf("\nAfter enQueuing 0,1,2,3,4,5 to the queue");
        printQueue(q1);

        deQueue(q1);
        printf("\nAfter deQueuing 0 from the queue");
        printQueue(q1);


                struct Queue* q2 = (struct Queue*)malloc(sizeof(struct Queue));
        q2->front = q2->rear = NULL;
        enQueue(q2, 10);
        enQueue(q2, 20);
        enQueue(q2, 30);
        enQueue(q2, 40);
        enQueue(q2, 50);

    printf("\nBefore copying Q1's content to Q2");
    printQueue(q2);

    copyQueue(q1,q2);

    printf("\nAfter copying Q1's content to Q2");
    printQueue(q2);

    //stack top is 5 here
    int stack[5] = {5,4,3,2,1};

    struct Queue *q3 = createQueueFromStack(stack);


    printf("\nPrinting Queue created from stack");
    printQueue(q3);

        return 0;
}
