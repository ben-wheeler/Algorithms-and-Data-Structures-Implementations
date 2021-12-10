#include <iostream>
#include <vector>

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

// class for Nodes
class EdgeNode
{
public:
    int vertex; // the adjacency info of each node
    EdgeNode *next; // pointer to next node in list
};              // end class initialisation

// adjacency list for each vertex with head as EdgeNode type
class AdjacencyList
{
public:
    EdgeNode *head; // Head EdgeNode for AdjacencyList vertex
};

// actual Graph
class Graph
{
public:
    int nVerticies;      // number of Vertex's in graph
    AdjacencyList *list; // the actual adjacency list, consisting of AdjacencyList class, and therefore Nodes
    vector<bool> visited;
    Graph(int num)       // default initialiser
    {
        nVerticies = num;                     // set the number of verticies equal to the number being initialised too
        list = new AdjacencyList[nVerticies]; // sets the list equal to a new List, with current number of verticies
        for (int i = 0; i < nVerticies; i++)  // going through each item in AdjacencyList
        {
            list[i].head = nullptr; // sets the head of each AdjacencyList item to be equal to NULL, as they contain no values
            visited.push_back(false);
        }
    }

    //graph / adjacencyList controls:
    void addEdge(int from, int to); // adds edge to graph
    void BFS();
    void print();                   // prints out adjacency list
};

void Graph::addEdge(int from, int to)
{
    EdgeNode *newNode = new EdgeNode();     // creates new instance of node
    newNode->vertex = to;           // creates a new node, whos vertex is the final destination of the edge (to)
    newNode->next = nullptr;        // sets the "next" pointer to point to nothing
    if (list[from].head == nullptr) // if "from" AdjacencyList head node currently has no edges
    {
        list[from].head = newNode; // "head" (first edge) of vertex = the new node
    }
    else // if "from" AdjacencyList head node currently has edges
    {
        EdgeNode *temp = list[from].head; // create a new pointer
        while (temp->next != nullptr)
        {
            temp = temp->next; // traverse tree with temp pointer
        }
        temp->next = newNode; // at final location, set next equal to the new pointer
    }
}

void Graph::print() // function used to print graph
{
    for (int i = 0; i < this->nVerticies; i++) // loop through each vertex
    {
        EdgeNode *temp = list[i].head; // temp pointer to transverse tree
        cout << i << " -> ";       // output vertex number
        while (temp != nullptr)    // loop to transverse edges
        {
            cout << temp->vertex; // print out edge connecting value
            if (temp->next != nullptr)
            {                 // for all but last
                cout << ", "; // print  comma between
            }
            temp = temp->next; // move to next
        }
        cout << endl; // at end of current vertix edges being printed, print new line
    }
}

void Graph::BFS(){
    
}

void testQueue(){ // driver with example operations
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

int main() // funtion driver
{
    Graph *AL = new Graph(4); // initialising AdjacenyList with 4 Vertex's
    AL->addEdge(0, 1);        // add edges between 0 and 1
    AL->addEdge(1, 2);
    AL->addEdge(2, 3);
    AL->addEdge(1, 3);
    AL->addEdge(3, 1);
    AL->addEdge(3, 2);

    AL->print(); // print out adjacency list
    cout << "------" << endl;
    testQueue();
}