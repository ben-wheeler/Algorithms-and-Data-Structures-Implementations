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
    Node *head;
};

// actual Graph
class Graph
{
public:
    int v;
    AdjacencyList *list;
    Graph(int n) // default initialiser
    {
        this->v = n;
        list = new AdjacencyList[this->v];
        for (int i = 0; i < this->v; i++)
        {
            list[i].head = nullptr;
        }
    }
    void addEdge(int x, int y);
    void print();
};

void Graph::addEdge(int x, int y)
{
    Node *nd = new Node();
    nd->vertex = y;
    nd->next = nullptr;
    if (list[x].head == nullptr)
    {
        list[x].head = nd;
    }
    else
    {
        Node *h = list[x].head;
        while (h->next != nullptr)
        {
            h = h->next;
        }
        h->next = nd;
    }
}

void Graph::print()
{
    for (int i = 0; i < this->v; i++)
    {
        Node *h = list[i].head;
        cout << i << "->";
        while (h != nullptr)
        {
            cout << h->vertex << " ";
            h = h->next;
        }
        cout << endl;
    }
}

int main()
{
    Graph g(4); // 4 is number of vertex in the Graph
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 3);
    g.print();
}