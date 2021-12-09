#include <iostream>
#include <vector>

#define MAXV 1000 // the max number of vertices

using namespace std;

// class for Nodes
class Node
{
public:
    int vertex; // the adjacency info of each node
    Node *next; // pointer to next node in list

    // constructor of new nodes
    Node()
    {
        next == NULL;
    }
}; // end class initialisation

// structure for linked list declaration
struct AdjacencyList
{
    vector<Node *> verticies;
    int numVerticies;
    AdjacencyList()
    {
    }
    // functions for controlling linkedList
    void addVertex(int x); // inserting at start of list
    void printList();      // prints entire list
    bool sortHelper()
    {
    }
    // void insertLast(int data); // inserting at end of list
    // void deleteFirst(); // deleting / removing first value in list
    // void deleteLast(); // deleting / removing last value in list
    // void updateTail(); // refactored function to simplfy layout of code, responsible for ensuring tail is correct
};

// refactored function to simplfy layout of code, responsible for ensuring tail is correct
// void AdjacencyList::updateTail(){
//     Node * nav = head; // creates temp pointer called nav to head
//     while(nav-> next != NULL){ // nav navigates the list while it's next pointer is not NULL
//         nav = nav->next; // nav moves to next item in list
//     }
//     tail = nav; // when nav->next == NULL, loop above stops, therefore at last item, which gets set as tail
// }

// inserting at start of list
void AdjacencyList::addVertex(int x)
{
    Node *temp = new Node;
    temp->vertex = x;
    verticies.push_back(temp);

    numVerticies = verticies.size();
    if (numVerticies == 0)
    {
        return;
    }
    else
    {
        verticies[numVerticies]->next = temp;
    }
}

// // inserting at end of list
// void AdjacencyList::insertLast(int data){ //
//     if(head == NULL){ // if head currently does not exist
//         head = new Node(data); // create head with data
//         tail = head; // head and tail both equal same node, as it is only one currently in list
//     }
//     else{ // if head already exists
//     Node * newNode = new Node(data); // create newNode
//     tail-> next = newNode; // set tail (last) nodes next to be equal to new node
//     updateTail(); // call to update tail, will become new node
//     }
// }

// // deleting / removing first value in list
// void AdjacencyList::deleteFirst(){
//     Node * nextNode = head-> next; // create pointer to new node, equal to 2nd value in list
//     free(head); // delete first
//     head = nextNode; // move head to be equal to the old 2nd value, as located by pointer
// }

// // deleting / removing last value in list
// void AdjacencyList::deleteLast(){
//     Node * nav = head; // pointer for traversing linked list
//     while(nav->next->next != NULL){ // while loop to navigate up till the 2nd to last node
//         nav = nav->next;
//     }
//     free(tail); // free the current tail
//     nav->next = NULL; // set new last node's next to be NULL
//     updateTail(); // updates last node to be tail
// }

// for printing linked list values
void AdjacencyList::printList()
{
    // Node *temp;
    // for (int i = 0; i < nvertices; i++)
    // {
    //     cout << i << ": ";
    //     temp = edges[i];
    //     while (temp != NULL)
    //     {
    //         cout << " " << temp->y;
    //         temp = temp->next;
    //     }
    //     cout << endl;
    // }
}

void printGraph(AdjacencyList * adj, int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << "\n Vertex " << i << ":";
        Node * temp = adj->verticies[i];
        while(temp != NULL)
        {
            cout << "-> " << temp->vertex;
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() // driver with example operations
{
    AdjacencyList *AL = new AdjacencyList; // initialising LinkedList
    // examples of manipulating linked list
    AL->addVertex(1);
    AL->addVertex(2);
    AL->addVertex(3);
    // AL->insertEdge(5);
    // AL->insertEdge(5);
    // AL->insertEdge(5);
    // AL->insertEdge(5);
    // AL->insertEdge(5);
    // printing linked list
    printGraph(AL, AL->numVerticies);
}