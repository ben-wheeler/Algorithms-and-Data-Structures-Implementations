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

// structure for linked list declaration
struct LinkedList{
    Node * head; // pointer to head
    Node * tail; // pointer to tail
    LinkedList(){ // default constructor, does nothing so head & tail both will equal NULL
    }

    // functions for controlling linkedList
    void insertFirst(int data); // inserting at start of list
    void insertLast(int data); // inserting at end of list
    void deleteFirst(); // deleting / removing first value in list
    void deleteLast(); // deleting / removing last value in list
    void printList(); // prints entire list
    void updateTail(); // refactored function to simplfy layout of code, responsible for ensuring tail is correct
};

// refactored function to simplfy layout of code, responsible for ensuring tail is correct
void LinkedList::updateTail(){
    Node * nav = head; // creates temp pointer called nav to head
    while(nav-> next != NULL){ // nav navigates the list while it's next pointer is not NULL
        nav = nav->next; // nav moves to next item in list
    }
    tail = nav; // when nav->next == NULL, loop above stops, therefore at last item, which gets set as tail
}

// inserting at start of list
void LinkedList::insertFirst(int data){
    if(head == NULL){ // if head currently does not exist
        head = new Node(data); // create head with data
        tail = head; // head and tail both equal same node, as it is only one currently in list
    }
    else{ // if head already exists
    Node * newNode = new Node(data); // create new node
    newNode-> next = head; // set newNode to be before current head 
    head = newNode; // set head to newNode
    updateTail(); // call to update tail;
    }
}

// inserting at end of list
void LinkedList::insertLast(int data){ //
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

// deleting / removing first value in list
void LinkedList::deleteFirst(){
    Node * nextNode = head-> next; // create pointer to new node, equal to 2nd value in list
    free(head); // delete first
    head = nextNode; // move head to be equal to the old 2nd value, as located by pointer
}

// deleting / removing last value in list
void LinkedList::deleteLast(){
    Node * nav = head; // pointer for traversing linked list
    while(nav->next->next != NULL){ // while loop to navigate up till the 2nd to last node
        nav = nav->next;
    }
    free(tail); // free the current tail
    nav->next = NULL; // set new last node's next to be NULL
    updateTail(); // updates last node to be tail
}

// for printing linked list values
void LinkedList::printList(){
   Node * nav = head; // creating node for navigating linkedList
	   while(nav != NULL){ // moves through entire linked list
      cout << nav->data ; // prints out data
      if(nav != tail){ // for all but last
          cout << ","; // print comma 
      }
      nav = nav->next; // move to next node, continue while loop
   }
   cout << endl; // after all nodes printed, print new line.
}

int main(){ // driver with example operations
    LinkedList * LL = new LinkedList; // initialising LinkedList
    
    // examples of manipulating linked list
    LL->insertFirst(3);
    LL->insertFirst(5);
    LL->insertFirst(5);
    LL->insertFirst(5);
    LL->insertFirst(5);
    LL->insertFirst(5);
    LL->insertFirst(5);
    LL->insertFirst(5);
    LL->insertLast(8);
    LL->deleteFirst();
    LL->deleteLast();

    // printing linked list
    LL->printList();
}