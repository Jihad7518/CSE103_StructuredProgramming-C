#include <stdio.h>
#include <stdlib.h>

struct node
{
int val;
struct node *next;
};struct node *head;


void show(){
    int i;
    struct node *ptr=head;
    if(ptr == NULL){
        printf("\n This LINKED LIST IS EMPTY!");
    }
    else{
        printf("\nELEMENTS ARE:  \n ");
        while(ptr!=NULL){
            printf("%d--->",ptr->val);
            ptr = ptr->next;
        }
         printf("NULL");
    }
}

void insert (){
    int number;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    scanf("%d",&number);
     ptr->val = number;
     ptr -> next = NULL;
    if(ptr == NULL){
        printf("\n FAILE TO ALLOCATE MEMORY !!");
    }
    else{
        if(head==NULL){
            head=ptr;
        }
        else{
            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;

            temp->next=ptr;
        }
    }
}

void removeDuplicates(struct node* head){
    struct node *ptr1, *ptr2, *dupply;
    ptr1 = head;

    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;

        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next != NULL) {
            /* If duplicate then delete it */
            if (ptr1->val == ptr2->next->val) {
                /* sequence of steps is important here */
                dupply = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dupply);
                dupply=NULL;
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}


    void main (){
        int i,num;
         printf("\nENTER THE NUMBER OF ELEMNTS: ");
         scanf("%d",&num);
         printf("\nENTER %d VALUES : ",num);
         for(i=0;i<num;i++){
            insert();
         }
         show();
         removeDuplicates(head);
         printf("\n\nAFTER REMOVING DUPLICATES: ");
         show();

    }
