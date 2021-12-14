#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << ",";
    }
    cout << "end of q" << endl;
}

// class for Nodes
class EdgeNode
{
public:
    int vertex;     // the adjacency info of each node
    EdgeNode *next; // pointer to next node in list
};                  // end class initialisation

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
    Graph(int num)       // default initialiser
    {
        nVerticies = num;                     // set the number of verticies equal to the number being initialised too
        list = new AdjacencyList[nVerticies]; // sets the list equal to a new List, with current number of verticies
        for (int i = 0; i < nVerticies; i++)  // going through each item in AdjacencyList
        {
            list[i].head = nullptr; // sets the head of each AdjacencyList item to be equal to NULL, as they contain no values
        }
    }

    //graph / adjacencyList controls:
    void addEdge(int from, int to); // adds edge to graph
    void print();                   // prints out adjacency list
    void BFS(int currentV);
};

void Graph::addEdge(int from, int to)
{
    EdgeNode *newNode = new EdgeNode(); // creates new instance of node
    newNode->vertex = to;               // creates a new node, whos vertex is the final destination of the edge (to)
    newNode->next = nullptr;            // sets the "next" pointer to point to nothing
    if (list[from].head == nullptr)     // if "from" AdjacencyList head node currently has no edges
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
        cout << i << " -> ";           // output vertex number
        while (temp != nullptr)        // loop to transverse edges
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

void Graph::BFS(int currentV)
{
    vector<bool> visited;
    for (int i = 0; i < nVerticies; i++)
    {
        visited.push_back(false);
    }

    vector<int> queue;

    visited[currentV] = true;
    queue.push_back(currentV);

    while (!queue.empty())
    {
        currentV = queue.front();
        cout << currentV << " ";
        queue.erase(queue.begin());

        EdgeNode *temp = list[currentV].head; // temp pointer to transverse tree
        int i = temp->vertex;
        while (temp != nullptr) // loop to transverse edges
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
            temp = temp->next; // move to next
            if (temp != nullptr)
            {
                i = temp->vertex;
            }
        }
    }
}

int main() // funtion driver
{
    Graph *AL = new Graph(4); // initialising AdjacenyList with 4 Vertex's
    AL->addEdge(0, 1);        // add edges between 0 and 1
    AL->addEdge(0, 2);
    AL->addEdge(1, 2);
    AL->addEdge(2, 0);
    AL->addEdge(2, 3);
    AL->addEdge(3, 3);

    AL->BFS(2); // print out adjacency list
    // AL->print();
}