#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node{
public:
    int data;    // the int value of each node
    Node *next;  // pointer to left child
    Node(int value){
        data = value;
    }
}; // end class initialisation

struct LinkedList{
    Node * head;
    LinkedList(){
    }
    void insert(int data);
    void deleteFirst();
    void printList();
    
};

void LinkedList::insert(int data){
    if(head == NULL){
        head = new Node(data);
    }
    else{
    Node * newNode = new Node(data);
    newNode-> next = head;
    head = newNode;
    }
}

void LinkedList::deleteFirst(){
    Node * nextNode = head-> next;
    free(head);
    head = nextNode;
}

void LinkedList::printList(){
   Node * ptr = head;
	
   //start from the beginning
   while(ptr != NULL){        
      cout << ptr->data << ",";
      ptr = ptr->next;
   }
	
}

int main(){
    LinkedList * LL = new LinkedList;
    LL->insert(3);
        LL->insert(5);

    LL->insert(5);

    LL->insert(5);

    LL->insert(5);

    LL->insert(5);


    LL->insert(5);
    LL->insert(5);
    LL->deleteFirst();


    LL->printList();
}