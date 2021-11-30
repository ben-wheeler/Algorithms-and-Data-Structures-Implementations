#include <iostream>

using namespace std;

// class for Nodes
class Node{
public:
    int data;    // the value of each node
    Node *next;  // pointer to next node

    // constructor of new nodes
    Node(int value){
        data = value; // sets Nodes data to be equal to value passed in
    }
}; // end class initialisation

// structure for queue declaration
struct Queue{
    Node * head; // pointer to head
    Node * tail; // pointer to tail
    Queue(){ // default constructor, does nothing so head & tail both will equal NULL
    }

    // functions for controlling queue
    void joinQueue(int data); // inserting at end of queue
    void enqueue(); // deleting / removing first item in queue
    void printQueue(); // prints entire queue
    void updateTail(); // refactored function to simplfy layout of code, responsible for ensuring tail is correct
    bool isEmpty(); // check if queue is empty
};

// check if queue is empty
bool Queue::isEmpty(){
    bool emptyStatus = false;
    if(head == NULL){
        emptyStatus = true;
    }
    return emptyStatus;
}
// refactored function to simplfy layout of code, responsible for ensuring tail is correct
void Queue::updateTail(){
    Node * nav = head; // creates temp pointer called nav to head
    while(nav-> next != NULL){ // nav navigates the queue while it's next pointer is not NULL
        nav = nav->next; // nav moves to next item in list
    }
    tail = nav; // when nav->next == NULL, loop above stops, therefore at last item, which gets set as tail
}

// inserting at end of queue
void Queue::joinQueue(int data){ //
    if(head == NULL){ // if head currently does not exist
        head = new Node(data); // create head with data
        tail = head; // head and tail both equal same node, as it is only one currently in list
    }
    else{ // if head already exists
    Node * newNode = new Node(data); // create newNode
    tail-> next = newNode; // set tail (last) nodes next to be equal to new node 
    updateTail(); // call to update tail, will become new node
    }
}

// deleting / removing first value in queue
void Queue::enqueue(){
    Node * nextNode = head-> next; // create pointer to new node, equal to 2nd value in list
    free(head); // delete first
    head = nextNode; // move head to be equal to the old 2nd value, as located by pointer
}

// for printing queue values
void Queue::printQueue(){
   Node * nav = head; // creating node for navigating queue
	   while(nav != NULL){ // moves through entire queue
      cout << nav->data ; // prints out data
      if(nav != tail){ // for all but last
          cout << ","; // print comma 
      }
      nav = nav->next; // move to next node, continue while loop
   }
   cout << endl; // after all nodes printed, print new line.
}

int main(){ // driver with example operations
    Queue * Q = new Queue; // initialising queue
    
    // examples of manipulating queue
    Q->joinQueue(3);
    Q->joinQueue(5);
    Q->joinQueue(5);
    Q->joinQueue(5);
    Q->joinQueue(5);
    Q->joinQueue(5);
    Q->joinQueue(5);
    Q->joinQueue(5);
    Q->joinQueue(8);
    Q->enqueue();

    // printing queue
    Q->printQueue();
}