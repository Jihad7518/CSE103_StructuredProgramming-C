#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 20
struct stack{

    int data;

    struct stack *next;

} *top = NULL, *newNode;

int main(){

    int choice, data, y;
    printf("  \n  ---- ---- ---- ---- ---- ---- Lab-02 ---- ---- ---- ---- ---- ----            \n\n");

    for(;;){

        printf("  \n\n  ---- ---- ---- MENU ---- ---- ----            \n");

        printf("  Enter (1) to Display\n");

        printf("  Enter (2) to Push\n");

        printf("  Enter (3) to Pop\n");

        printf("  Enter (4) to Parsing Unmatched Parenthesis\n");

        printf("  Enter (5) to determine if the input string is valid.\n");

        printf("  Enter (6) to Reversing Data(Decimal to binary).\n");

        printf("  Enter (7) to Exit\n");

        printf("  ---------------------------------\n");

        printf("\nEnter your choice between (1-7): ");

        scanf("%d", &choice);

        switch(choice){

            case 1:

                display();

                break;

            case 2:

                printf("Enter your value: ");

                scanf("%d", &y);

                push(y);

                break;

            case 3:

                pop();

                break;

            case 4:

                parsing();

                break;

            case 5:

                validchar();

                break;

            case 6:

                reversing();

                break;

            case 7:

                exit(0);

                break;
        }

        printf("\n");
    }
    return 0;
}

void display(){

    printf("\n\n    --- --- Display value --- ---   \n");

    struct stack *temp = top;

    if(temp==NULL){

        printf("\nStack is empty");

    }

    while(temp != NULL){

        printf("%d  ", temp -> data);

        temp = temp -> next;

    }
printf("\n  ---------------------------------\n");

}

void push(int a){

    newNode = (struct stack *)malloc(sizeof(struct stack));

    newNode->data = a;

    if(top == NULL){

        newNode->next = NULL;

        top = newNode;

    }else{

        newNode->next = top;

        top = newNode;

    }

}

int pop(){

    struct stack *temp;

    if(top==NULL){

        printf("\n Stack is empty");

    }

    if(top != NULL){

        temp = top;

        top = top->next;

        free(temp);

    }

}

struct stack1{

    char data1;

    struct stack1 *next1;

} *top1 = NULL, *newNode1;

void push1(){

        newNode1 = (struct stack1 *)malloc(sizeof(struct stack1));

        newNode1->data1 = '(';

        if(top1 == NULL){

            newNode1->next1 = NULL;

            top1 = newNode1;

        }else{

            newNode1->next1 = top1;

            top1 = newNode1;

        }

    }

int pop1(){

    struct stack *temp1;

    if(top1 != NULL){

        temp1 = top1;

        top1 = top1->next1;

        free(temp1);

    }

}

void parsing(){

    int i, c = 0,p=0,q=0;

    char equation[20];

    printf("\n  Enter equation: ");

    scanf("%s", &equation);

    for(i = 0; i < sizeof(equation); i++){

        if(equation[i] == '('){
            push1();
            ++c;
        }

        if(equation[i] == ')'){
            if(c != 0){
                pop1();
                --c;
            }
            else{
                ++c;
                printf("\n Closing parentheses not matched..!!");
                break;
            }
        }
        if(equation[i] == '{'){

            push1();
            ++p;
        }

        if(equation[i] == '}'){
            if(p != 0){
            pop1();
                --p;
            }
            else{
                ++p;
                printf(" \n Closing parentheses not matched..!!");
                break;
            }
        }
        if(equation[i] == '['){
            push1();
            ++q;
        }
        if(equation[i] == ']'){
            if(q != 0){
                pop1();
                --q;
            }
            else{++q;
                printf(" \n Closing parentheses not matched..!!");
                break;
            }
        }
    }
    if(top1 != NULL && top1->data1 == '('){
        printf("\n Opening parentheses not end..!!");
        pop1();
    }
    if(top1 != NULL && top1->data1 == '{'){
        printf("\n Opening parentheses not end..!!");
        pop1();
    }
    if(top1 != NULL && top1->data1 == '['){
        printf("\n Opening parentheses not end..!!");
        pop1();
    }
    if (c==0 && p==0 && q==0) {printf("\n Equal brackets in this parentheses");}

}

void reversing(){
    struct stack *temp;
    int x, c = 0, i;
    printf("\n Enter the decimal number: ");
    scanf("%d", &x);
    while(x > 0){
        push(x % 2);
        c++;
        x = x /2;
    }
    printf("\n");
    while(c>0){
        temp = top;
        printf("%d", temp -> data);
        top = top -> next;
        free(temp);
        c--;
    }
    printf("\n");
}

struct stack3
{
char stk[MAX];
int top;
}s;

void push2(char item)
{
if (s.top == (MAX - 1))
printf ("Stack is Full\n");
else
{
s.top = s.top + 1;
s.stk[s.top] = item;
}}

void pop2()
{
if (s.top == - 1)
{
printf ("Stack is Empty\n");
}
else
{
s.top = s.top - 1;
}}

void validchar(){

char exp[MAX];
int i = 0;
s.top = -1;
printf("\nINPUT THE EXPRESSION : ");
scanf("%s", exp);
for(i = 0;i < strlen(exp);i++)
{
    if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
    {
    push2(exp[i]);
    continue;
    }
    else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
    {
    if(exp[i] == ')')
    {
    if(s.stk[s.top] == '(')
    {
    pop2();
    }
    else
    {
    printf("\nParenthesis are invalid \n");
    exit(0);
    }}
    if(exp[i] == ']')
    {
    if(s.stk[s.top] == '[')
    {
    pop2();
    }
    else
    {
    printf("\nParenthesis are invalid \n");
    exit(0);
    }}
    if(exp[i] == '}')
    {
    if(s.stk[s.top] == '{')
    {
    pop2();
    }
    else
    {
    printf("\Parenthesis are invalid\n");
    exit(0);
    }}}}
if(s.top == -1)
{
printf("\nParenthesis are valid \n");
}
else printf("\n Parenthesis are invalid\n");


}
