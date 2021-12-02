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

struct BinaryTree // structure for binary tree
{
    Node * root; // root of tree
    void insert(int value); // helper function to call insertNode or initialise root node to hold first value
    void del(int value); // helper function to delete nodes
    Node * insertNode(Node *current, int value); // actual function for inserting, takes in the current looked at node (starts as root, changes recursively) and value to add
    Node * deleteNode(Node *current, int value); // actual function for deleting, takes in the current looked at node (starts as root, changes recursively) and value to delete
    Node * search(Node *current, int value); // takes in BT root + value looking for 
    Node * minNodeSubtree(Node *node); // function to assist with deleting

    BinaryTree(){ // default initaliser, sets root to null
        root = NULL;
    }
};

void BinaryTree::insert(int x) // helper function to call insertNode or initialise root node to hold first value
{
    if(root == NULL){ // if root == null (entire tree is empty)
        root = new Node(x); // root = new node with value
    }
    else{ // creates new node as roots left or right child, calls real insert Node function
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

    void BinaryTree::del(int value){ // helper delete function
       deleteNode(root, value); // calls real delete function, adds root, to simpfily user's usege of calling function with just value to delete.
    }


Node * BinaryTree::insertNode(Node * current, int x){ // insert function
    if (current == NULL) // base case, standard binary tree
    {
        return new Node(x); // create a new node with data
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

up to here
Node * BinaryTree::search(Node * current, int x){ // search function, returns node address
    if (current == NULL) // case, node not in tree
    {
        return NULL; // returns null
    }

    else if (current->data == x) // base case, standard binary tree
    {
        return current; // create a new node with data
    }
    else if (x < current->data) // if data is less then current root/branch of the tree
    {
        search(current->left, x); // recersive call, travels down tree, to left
    }
    else if (x > current->data) // if data is greator then current root/branch of the tree
    {
    search(current->right, x); // recersive call, travels down tree, to right
    }
    return current; // return unchanged node
}

Node * BinaryTree::minNodeSubtree(Node *node) // function for finding max node of a subtree
{
    Node *current = node; // creates temp node

    while (current->left != NULL)
    { // keeps travelling down tree, while next right != NULL
        current = current->left;
    }
    return current; // returns location of max node of a subtree
}

Node * BinaryTree::deleteNode(Node * current, int x){
    if (current == NULL) // base case, standard binary tree
    {
        return current; // create a new node with data
    }
    if (x < current->data) // if data is less then current root/branch of the tree
    {
        current->left = deleteNode(current->left, x); // recersive call, travels down tree, to left
    }
    else if (x > current->data) // if data is greator then current root/branch of the tree
    {
        current->right = deleteNode(current->right, x); // recersive call, travels down tree, to right
    }
    else
    {
        if ((current->left == NULL) || (current->right == NULL)) // if there is one or no child
        {
            Node *temp; // inisitalise temparory node
            if (current->left != NULL)
            {                      // if left child exists
                temp = current->left; // temp = left child
            }
            else
            {                       // if no left child
                temp = current->right; // temp equals right child
            }
            // No child, ie, both = NULL;
            if (temp == NULL)
            {
                current = NULL; // current node = nothing (deletes data)
            }
            else             // Right/Left != Null, therefore one child case
                current = temp; // if there was child, node = child (deletes data)
        }
        else // if two children
        {
            Node *temp = minNodeSubtree(current->right);         // temp node equals max value from left child's subtree
            current->data = temp->data;                         // node's data = max value from left child's subtree
            current->right = deleteNode(current->right, temp->data); // left child = recursive call to delete nax value;
        }
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
    BT->del(5);
    
    cout << BT->search(BT->root,11) << endl;
        preOrder(BT->root);
}