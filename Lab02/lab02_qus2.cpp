#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
    }
};


class Queue {
  public:

    Node *head= NULL;
    Node *newdata= NULL;

    void enque(int item) {      // Insert data in last
        newdata = new Node(item);

        if(head==NULL) {
            head = newdata;
        } else {
            Node *temp = head;
            while(temp -> next != NULL ) {
                temp = temp -> next;
            }
            temp -> next = newdata;
            newdata -> next = NULL;
        }
    }

    int size() {        // Count amount of data from 0
        Node *temp= head;
        int count = 0;
        while(temp!= NULL) {
            temp = temp->next;
            count++ ;
        }
        return count;
    }
    bool isEmpty() {    // return true if queue is empty
        if(head == NULL)return true;
        else return false;
    }

    void deque() {  //Remove data from front
        Node* temp = head -> next;
        delete head;
        head = temp;

    }
    int show() { // show first data
        return head -> data;
    }
    void showAll(){ // show all data
        for( int i = 0 ; i < size() ; i++ ){
        int temp = show();
        cout << temp << " ";
        deque();
        enque(temp);
        }
        }

};
int main(){
    Queue* queueMain = new Queue();
    Queue* queueCopy = new Queue();
    int temp;
    for( int i = 0 ; i < 5 ; i++ ){
    cin >> temp;
    queueMain -> enque(temp);
    }
    for( int i = 0 ; i < queueMain -> size() ; i++ ){
    queueCopy -> enque( queueMain -> show() );
    temp = queueMain -> show();
    queueMain -> deque();
    queueMain -> enque(temp);
    }
    queueCopy -> showAll();
}


int main() {
    Queue* queueMain = new Queue();
    Queue* queueCopy = new Queue();
    int temp, flag = 0;
    for( int i = 0 ; i < 5 ; i++ ) {
        cin >> temp;
        queueMain -> enque(temp);
    }
    cout << "Group1: ";
    for( int i = 0 ; i < 5 ; i++ ) {
        if( queueMain -> show() < 18){
        cout << queueMain -> show() << " ";
        flag = 1;
        }
            temp = queueMain -> show();
            temp = queueMain -> show();
            queueMain -> deque();
            queueMain -> enque(temp);
            flag = 1;

    }
    if( flag == 0 )cout << "NULL" << endl;
    else {
    cout << endl;
    flag = 0;
    }
    cout << "Group2: ";
    for( int i = 0 ; i < 5 ; i++ ) {
        if( queueMain -> show() >= 18 && queueMain -> show() <= 35 ){
        cout << queueMain -> show() << " ";
        flag = 1;
        }
            temp = queueMain -> show();
            temp = queueMain -> show();
            queueMain -> deque();
            queueMain -> enque(temp);
            flag = 1;
    }
    if( flag == 0 )cout << "NULL" << endl;
    else {
    cout << endl;
    flag = 0;
    }
    cout << "Group3: ";
    for( int i = 0 ; i < 5 ; i++ ) {
        if( queueMain -> show() >= 36 && queueMain -> show() <= 45 ){cout << queueMain -> show() << " ";
        flag = 1;
        }
            temp = queueMain -> show();
            temp = queueMain -> show();
            queueMain -> deque();
            queueMain -> enque(temp);
            flag = 1;

    }
    if( flag == 0 )cout << "NULL" << endl;
    else {
    cout << endl;
    flag = 0;
    }
    cout << "Group4: ";
    for( int i = 0 ; i < 5 ; i++ ) {
        if( queueMain -> show() >= 46 ){
        cout << queueMain -> show() << " ";
        flag = 1;
        }
            temp = queueMain -> show();
            queueMain -> deque();
            queueMain -> enque(temp);
    }
    if( flag == 0 )cout << "NULL" << endl;
    else {
    cout << endl;
    flag = 0;
    }
}
