#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void reverse(struct Node **head){
    struct Node *temp = NULL;
    struct Node *current = *head;

    while (current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if(temp != NULL ){
        *head = temp->prev;
    }
}

void InsertAtstart(struct Node** head, int new_data){

    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));

    new_node->data = new_data;


    new_node->prev = NULL;

    new_node->next = (*head);

    if((*head) != NULL)
        (*head)->prev = new_node ;

        (*head) = new_node;

}


void printList(struct Node *node){
    while(node!=NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}


int main(){
    struct Node* head = NULL;

    InsertAtstart(&head, 2);
    InsertAtstart(&head, 4);
    InsertAtstart(&head, 8);
    InsertAtstart(&head, 10);

    printf("\n Original Linked list ");
    printList(head);

    /* Reverse doubly linked list */
    reverse(&head);

    printf("\n Reversed Linked list ");
    printList(head);

    getchar();
}
