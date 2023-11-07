# Graph Traversal Algorithms in C

## Introduction
This C code demonstrates the implementation of two graph traversal algorithms: Breadth-First Search (BFS) and Depth-First Search (DFS) using an adjacency list representation of a graph. These algorithms are fundamental for exploring and navigating graphs.

## Data Structures
1. `struct node`: A data structure to represent a node in the adjacency list, containing vertex (v), edge weight (w), and a pointer to the next node.
2. `adj_list`: An array of linked lists to represent the graph's adjacency list.

## Functions
1. `create_node`: Creates a new node with the specified vertex and weight.
2. `add_edge`: Adds an edge between two vertices by appending a new node to the appropriate linked list in the adjacency list.
3. `print_adjacency_list`: Displays the adjacency list for the graph.

## Breadth-First Search (BFS)
1. `BFS`: Implements BFS to traverse the graph starting from a specified vertex.
2. The BFS algorithm uses a queue data structure to explore vertices in layers.

## Depth-First Search (DFS)
1. `DFS`: Implements DFS to traverse the graph starting from a specified vertex.
2. The DFS algorithm uses a stack data structure to explore vertices deeply before backtracking.

## Main Function
1. The `main` function initializes the number of vertices and an adjacency matrix representing the graph.
2. It populates the adjacency list using the `add_edge` function based on the adjacency matrix.
3. The adjacency list is printed using the `print_adjacency_list` function.
4. BFS is performed, starting from a specified vertex and printing the traversal order.
5. DFS is performed, starting from a specified vertex and printing the traversal order.

## Example Usage
1. Compile and run the code to perform BFS and DFS traversals on the provided graph.
2. Observe the order in which the vertices are visited and printed during the traversals.

## Note
- Ensure that the code is correctly implemented and compiles successfully.
- Modify the code to work with different graphs by changing the adjacency matrix and specifying the starting vertices for BFS and DFS.
