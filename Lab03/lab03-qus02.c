#include<stdio.h>
#include<stdlib.h>

//defining a simple structure to represent a node
typedef struct node_{
        //has integer data field
        int data;
        //and a pointer to the next node
        struct node_ *next;
} Node;

//this method takes the head node, and a new data value, and
//adds a new node with given data before head, and returns the
//new head node
Node* push(Node *head, int data){
        //allocating memory for a new node
        Node* node = (Node*) malloc(sizeof(Node));
        //setting current head as next of new node
        node->next=head;
        //setting data as node->data
        node->data=data;
        //returning new head node
        return node;
}


int main(){
        //initializing empty stack
        Node* head = NULL;
        //pushing several values to the stack (note the syntax)
        head = push(head, 1);
        head = push(head, 2);
        head = push(head, 3);
        head = push(head, 4);
        //now looping, popping and displaying the stack elements until
        //stack is empty. elements should be printed in reverse order
        while(head != NULL){
                //fetching current head reference
                Node* curr = head;
                //advancing head reference
                head = head->next;
                //printing data of curr
                printf("%d\n",curr->data);
                //deleting curr from memory to prevent memory leaks
                free(curr);
        }
        return 0;
}
