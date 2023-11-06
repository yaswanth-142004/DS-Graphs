# Breadth-First Search (BFS) Algorithm for Graph Traversal

## Introduction
This code performs a Breadth-First Search (BFS) traversal on a graph represented as an adjacency list. BFS is used to explore a graph in layers, starting from a specified vertex.

## Algorithm
1. Define a structure for a node in the adjacency list, which includes the vertex (v), edge weight (w), and a pointer to the next node.
2. Initialize an array of linked lists (adjacency list) to represent the graph, with each element in the array corresponding to a vertex.
3. Create a function `create_node` to create a new node with the given vertex and weight.
4. Implement a function `add_edge` to add an edge between two vertices by appending a new node to the appropriate linked list in the adjacency list.
5. Create a function `print_adjacency_list` to display the adjacency list for the graph.

## Breadth-First Search (BFS) Implementation
1. Define a queue data structure to keep track of vertices to be visited in BFS.
2. Implement functions for queue operations, including `is_full`, `is_empty`, `enqueue`, and `dequeue`.
3. Implement a `BFS` function that takes a starting vertex and the number of vertices as arguments.
4. In the `BFS` function, initialize an array to track visited vertices.
5. Start from the given vertex, mark it as visited, and enqueue it in the queue.
6. While the queue is not empty, dequeue a vertex, print it as visited, and explore its adjacent vertices, marking them as visited and enqueuing them if not already visited.
7. Continue this process until the queue is empty, and the BFS traversal is complete.

## Main Function
1. In the `main` function, specify the number of vertices and define the adjacency matrix for the graph.
2. Populate the adjacency list by adding edges based on the adjacency matrix.
3. Print the adjacency list.
4. Call the `BFS` function to perform a BFS traversal starting from a specified vertex.

## Example Usage
1. Compile and run the code to perform a BFS traversal on the given graph.
2. Observe the order in which the vertices are visited and printed during the traversal.

## Note
- Ensure that the code is correctly implemented and compiles successfully.
- Modify the code as needed to work with different graphs by changing the adjacency matrix.
