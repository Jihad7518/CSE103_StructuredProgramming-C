#include <iostream>
using namespace std;

//Node struct declaration
struct Node {
    int info;
    Node* next;
};

//Queue class declaration
class Queue {
private:
    Node* front; //pointer to front node
    Node* rear; //pointer to rear node
    int count; //number of elements in Queue
public:
    Queue(); // constructor
    bool isEmpty(); // method to check if the Queue is empty
    int size(); // return the number of elements in the Queue
    void enqueue(int x); // method to insert a value to the Queue
    int dequeue(); // method to delete the front element from the Queue
    ~Queue(); // destructor
};


//constructor implementation
Queue::Queue()
{
        //initializing both pointers to null
    front = NULL;
    rear = NULL;
    count = 0;
}


//destructor implementation
Queue::~Queue()
{
        Node* temp;
    //loop until front is NULL
    while (front != NULL) {
        temp = front;
        front = front->next;
        //deleting temp to prevent memory leakage
        delete temp;
    }
    rear=NULL;
    count = 0;
}



//returns true if Queue is empty, else false
bool Queue::isEmpty()
{
    return count == 0;
}


//returns the length of Queue
int Queue::size()
{
    return count;
}


//pushes an element to rear of Queue
void Queue::enqueue(int x)
{
        //creating a new node
    Node* node = new Node();
    //setting x as info
    node->info = x;
    //NULL as next
    node->next = NULL;
    //if this is first value, setting as front and rear
    if(count==0){
        //updating front and rear
        front=node;
        rear=node;
        }else{
                //otherwise appending to rear, updating rear
                rear->next=node;
                rear=node;
        }
    count++;
}

//removes an element from front

int Queue::dequeue()
{
    if (!isEmpty()) {
        int data = front->info;
        Node* temp=front;
        //advancing front
        front = front->next;
        //deleting removed node to save memory
        delete temp;
        //updating count
        count--;
        //if count is 0, setting front and rear to NULL
        if(count==0){
                front=NULL;
                rear=NULL;
                }
                //returning removed value
                return data;
    }
    return -1; //if queue is empty.
}


//method to delete negative values from a queue
//this won't work if queue is not passed by reference.
void deleteNegatives(Queue &q){
        //finding queue size
        int size=q.size();
        //looping for size times
        for(int i=0;i<size;i++){
                //removing front element
                int value=q.dequeue();
                //if value is 0 or positive, adding removed value to the end
                if(value>=0){
                        q.enqueue(value);
                }
        }
        //after size number of iterations, queue will be back in original order,
        //excluding all negative values.
}


int main(){
        //creating a queue
        Queue q;
        //adding some values
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(-3);
        q.enqueue(4);
        q.enqueue(-5);

        //deleting all negatives
        deleteNegatives(q);

        //printing updated queue
        while(!q.isEmpty()){
                cout<<q.dequeue()<<" ";
        }
        cout<<endl;
        return 0;
}
