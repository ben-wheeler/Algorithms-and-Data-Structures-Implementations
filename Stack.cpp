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

// structure for stack declaration
struct Stack{
    Node * head; // pointer to head / top of stack
    Stack(){ // default constructor, does nothing so stack will be initalised to NULL
    }

    // functions for controlling stack
    void push(int data); // inserting into stack
    void pop(); // deleting / removing from stack
    void printStack(); // prints entire stack
    bool isEmpty(); // check if stack is empty
};

// check if stack is empty
bool Stack::isEmpty(){
    bool emptyStatus = false;
    if(head == NULL){
        emptyStatus = true;
    }
    return emptyStatus;
}

// inserting into stack
void Stack::push(int data){
    if(head == NULL){ // if head currently does not exist
        head = new Node(data); // create head with data
    }
    else{ // if head already exists
    Node * newNode = new Node(data); // create new node
    newNode-> next = head; // set newNode to be before current head 
    head = newNode; // set head to newNode
    }
}

// deleting from stack
void Stack::pop(){
    Node * nextNode = head-> next; // create pointer to new node, equal to 2nd value in list
    free(head); // delete first value in stack
    head = nextNode; // move head of stack to be equal to the old 2nd value, as located by pointer
}

// for printing stack values
void Stack::printStack(){
   Node * nav = head; // creating node for navigating stack
	   while(nav != NULL){ // moves through entire stack
      cout << nav->data; // prints out data
      if(nav->next != NULL){ // for all but last
          cout << ","; // print comma 
      }
      nav = nav->next; // move to next node, continue while loop
   }
   cout << endl; // after all nodes printed, print new line.
}

int main(){ // driver with example operations
    Stack * S = new Stack; // initialising stack
    
    // examples of manipulating stack
    S->push(3);
    S->push(5);
    S->push(5);
    S->push(5);
    S->push(5);
    S->push(5);
    S->push(5);
    S->push(5);
    S->push(8);
    S->pop();

    // printing stack
    S->printStack();
}