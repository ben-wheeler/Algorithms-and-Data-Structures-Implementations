# Algorithms and Data Structures Implementations
 
## Linked List
A simple example of a linked list in C++. Controlable via main driver within file.
#### Features:
- Creation of elements in the first or last positions of the list.
- Deleting elements in first or last positions.
- Ability to print all values in list.
- See full list of functions within `struct LinkedList`

**Compile and Run using:** `make LinkedList`

## Stack
A simple example of a FILO stack in C++. Controlable via main driver within file. Based on LinkedList.
#### Features:
- Push elements onto stack.
- Pop elements off of stack.
- Ability to print stack values.
- See full list of functions within `struct Stack`

**Compile and Run using:** `make FILOStack`

## Queue
A simple example of a queue in C++. Controlable via main driver within file. Based on LinkedList.
#### Features:
- Queue elements at back of the queue 
- Enqueue elements from front of the queue
- Ability to print queue values.
- See full list of functions within `struct Queue`

**Compile and Run using:** `make Queue`

## Binary Tree
A simple example of a Binary Tree in C++. Controlable via main driver within file.
#### Features:
- Insert elements using `Binary Tree Name->insert(<int>)`
- Delete elements using `Binary Tree Name->insert(<int>)`
- Search elements using `Binary Tree Name->insert(<binary tree root node pointer>,<int>)`
- Print tree using `preOrder(<binary tree root node pointer>)`

**Compile and Run using:** `make BinaryTree`


## Adjacency List 
WIP Single Direction Adjacency List 
A simple example of an Adjacency List in C++. Controlable via main driver within file.
#### Features:
- Initalalise Tree to have x vertex elements using `->Graph * <Adjacency List Name> = new Graph(x);`
- Add elements to tree using `<Adjacency List Name>->addEdge(from, to);`
- Print graph using `<Adjacency List Name>->print()`

**Compile and Run using:** `make AdjacenyList`

