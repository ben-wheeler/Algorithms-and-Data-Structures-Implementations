#include <iostream>

using namespace std;

// class for Nodes
class Node
{
public:
    int data;    // the value of each node
    Node *left;  // pointer to left node
    Node *right; // pointer to right node

    // constructor of new nodes
    Node(int value)
    {
        data = value; // sets Nodes data to be equal to value passed in
        left = NULL;
        right = NULL;
    }
    Node(){}
}; // end class initialisation

struct BinaryTree
{
    Node * root;
    void insert(int value);
    Node * insertNode(Node *current, int value);
    BinaryTree(){
        root = NULL;
    }
};

void BinaryTree::insert(int x)
{
    if(root == NULL){
        root = new Node(x);
    }
    else{
    if (x < root->data) // if data is less then current root/branch of the tree
    {
        root->left = insertNode(root->left, x); // recersive call, travels down tree, to left
    }
    else if (x > root->data) // if data is greator then current root/branch of the tree
    {
        root->right = insertNode(root->right, x); // recersive call, travels down tree, to right
    }
}
}

Node * BinaryTree::insertNode(Node * current, int x){
    if (current == NULL) // base case, standard binary tree
    {
        return new Node(x);; // create a new node with data
    }
    if (x < current->data) // if data is less then current root/branch of the tree
    {
        current->left = insertNode(current->left, x); // recersive call, travels down tree, to left
    }
    else if (x > current->data) // if data is greator then current root/branch of the tree
    {
        current->right = insertNode(current->right, x); // recersive call, travels down tree, to right
    }
    else
    {                // if == existing
        return current; // return node
    }
    return current; // return unchanged node
}

void preOrder(Node *node) // for printing node in preOrder
{
    if (node != NULL) // stops recursive call when an empty child/node is found
    {
        cout << node->data << " "; // prints data at node
        preOrder(node->left);      // prints left
        preOrder(node->right);     // prints right
    }
}

int main()
{
    BinaryTree *BT = new BinaryTree();
    BT->insert(5);
    BT->insert(3);

    BT->insert(2);

    BT->insert(7);
    BT->insert(6);
    preOrder(BT->root);
}