#include <iostream>

using namespace std;

// class for Nodes
class Node
{
public:
    int vertex; // the adjacency info of each node
    Node *next; // pointer to next node in list
};              // end class initialisation

// adjacency list for each vertex with head as Node type
class AdjacencyList
{
public:
    Node *head; // Head Node for AdjacencyList vertex
};

// actual Graph
class Graph
{
public:
    int nVerticies; // number of Vertex's in graph
    AdjacencyList *list; // the actual adjacency list, consisting of AdjacencyList class, and therefore Nodes 
    Graph(int num) // default initialiser
    {
        nVerticies = num; // set the number of verticies equal to the number being initialised too
        list = new AdjacencyList[nVerticies]; // sets the list equal to a new List, with current number of verticies
        for (int i = 0; i < nVerticies; i++) // going through each item in AdjacencyList
        {
            list[i].head = nullptr; // sets the head of each AdjacencyList item to be equal to NULL, as they contain no values
        }
    }
    
    //graph / adjacencyList controls:
    void addEdge(int from, int to); // adds edge to graph
    void print(); // prints out adjacency list
};

void Graph::addEdge(int from, int to)
{
    Node *newNode = new Node(); // creates new instance of node
    newNode->vertex = to; // sets vertex node is pointing to, to the value of to
    newNode->next = nullptr; // sets the "next" pointer to point to nothing
    if (list[from].head == nullptr) // if "from" AdjacencyList head node currently has no edges
    {
        list[from].head = newNode; // "head" (first edge) = the new node (edge)
    }
    else // if "from" AdjacencyList head node currently has edges
    {
        Node *temp = list[from].head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void Graph::print()
{
    for (int i = 0; i < this->nVerticies; i++)
    {
        Node *temp = list[i].head;
        cout << i << " -> ";
        while (temp != nullptr)
        {
            cout << temp->vertex;
            if(temp->next != nullptr){
                cout << ", ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    Graph *AL = new Graph(4); // initialising LinkedList
    AL->addEdge(0, 1);
    AL->addEdge(1, 2);
    AL->addEdge(2, 3);
    AL->addEdge(1, 3);
    AL->print();
}