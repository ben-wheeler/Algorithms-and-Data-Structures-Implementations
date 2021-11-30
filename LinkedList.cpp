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
    Node * tail;
    LinkedList(){
    }
    void insertFirst(int data);
    void insertLast(int data);
    void deleteFirst();
    void deleteLast();
    void printList();
    void updateTail();
};

void LinkedList::updateTail(){
    Node * nav = head;
    while(nav-> next != NULL){
        nav = nav->next;
    }
    tail = nav;
}

void LinkedList::insertFirst(int data){
    if(head == NULL){
        head = new Node(data);
    }
    else{
    Node * newNode = new Node(data);
    newNode-> next = head;
    head = newNode;
    updateTail();
    }
}

void LinkedList::insertLast(int data){
    if(head == NULL){
        head = new Node(data);
    }
    else{
    Node * newNode = new Node(data);
    tail-> next = newNode;
    updateTail();
    }
}

void LinkedList::deleteFirst(){
    Node * nextNode = head-> next;
    free(head);
    head = nextNode;
}

void LinkedList::deleteLast(){
    Node * nav = head;
    while(nav->next->next != NULL){
        nav = nav->next;
    }
    free(tail);
    nav->next = NULL;
    updateTail();
}

void LinkedList::printList(){
   Node * ptr = head;
	
   //start from the beginning
   while(ptr != NULL){        
      cout << ptr->data ;
      if(ptr != tail){
          cout << ",";
      }
      ptr = ptr->next;
   }
   cout << endl;
}

int main(){
    LinkedList * LL = new LinkedList;
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
    LL->printList();
}