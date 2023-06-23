#include <string>
#include <queue>
#include <iostream>
using namespace std;



void copyQueue(queue<string> tempQ){

cout<<"Temp Queue size: "<<tempQ.size()<<endl;

 cout << "Input Data are: "<<endl;
 while(!tempQ.empty())
 {
 string data = tempQ.front().c_str();
 std::cout << data <<"\n";

tempQ.pop();

}
}
int main()
{
 //Create a queue
 queue<string> numbersQueue;

/*
 *Insert elements in to the Q1
 */
 cout << "Inserting elements into Q1\n";
 numbersQueue.push("1");
 numbersQueue.push("2");
 numbersQueue.push("3");
 numbersQueue.push("4");
 numbersQueue.push("5");

cout<< "Q1 size: "<<numbersQueue.size()<<endl;



//copy queue to another queue
 copyQueue(numbersQueue);

/*
 *Check if original queue contains and elements
 and not popped by temp queue
 */
 cout<< "Q2 size: "<<numbersQueue.size()<<endl;;

//Process orinial queue
 cout << "OutPut Data are: "<<endl;
 while(!numbersQueue.empty()) {

//front() function returns firsts element
 //but does not delete it from queue
 cout <<numbersQueue.front() << "\n";

//To delete front element from the queue.
 numbersQueue.pop();
 }

cout << endl;

return 0;
}
