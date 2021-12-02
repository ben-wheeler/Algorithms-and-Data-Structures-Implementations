#include <iostream>

using namespace std;

// class for Nodes
class Node
{
public:
    int data;     // the value of each node
    Node *left;  // pointer to left node
    Node *right; // pointer to right node

    // constructor of new nodes
    Node(int value)
    {
        data = value; // sets Nodes data to be equal to value passed in
        left = NULL;
        right = NULL;
    }
}; // end class initialisation

struct BinaryTree
{
    Node * root;
};
