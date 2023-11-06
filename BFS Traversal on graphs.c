#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int v;
    int w;
    struct node* next;
};

struct node* adj_list[100] = {NULL};

struct node* create_node(int value, int weight) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node) {
        new_node->v = value;
        new_node->w = weight;
        new_node->next = NULL;
    }
    return new_node;
}

void add_edge(int vertex, int value, int weight) {
    struct node* new_node = create_node(value, weight);
    if (new_node) {
        if (adj_list[vertex] == NULL) {
            adj_list[vertex] = new_node;
        } else {
            struct node* temp = adj_list[vertex];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
}

void print_adjacency_list(int size) {
    for (int i = 0; i < size; i++) {
        printf("for V%d", i + 1);
        if (adj_list[i] != NULL) {
            struct node* temp = adj_list[i];
            while (temp != NULL) {
                printf(" -> (V%d, %d)", temp->v + 1, temp->w);
                temp = temp->next;
            }
            printf("\n");
        } else {
            printf(" = no adjacent edges\n");
        }
    }
}

int queue[9] = {0};
int rear = -1;
int front = -1;

bool is_full() {
    if (front == 9)
        return true;
    else
        return false;
}
bool is_empty() {
    if (rear == front && front != -1)
        return true;
    else
        return false;
}
void enqueue(int n) {
    if (!(is_full())) {
        queue[front++] = n;
    }
}
int dequeue() {
    if (!(is_empty())) {
        return queue[rear++];
    }
}

void BFS(int start_vertex, int num_of_vertex) {
    bool visited[num_of_vertex];
    for (int i = 0; i < num_of_vertex; i++) {
        visited[i] = false;
    }
    visited[start_vertex] = true;
    enqueue(start_vertex);
    printf("Breadth-First Search starting from vertex: V%d\n", start_vertex + 1);
    while (!is_empty()) {
        int current = dequeue();
        printf("Visited V%d\n", current + 1);
        struct node* temp = adj_list[current];
        while (temp != NULL) {
            int adj_vertex = temp->v;
            if (!visited[adj_vertex]) {
                visited[adj_vertex] = true;
                enqueue(adj_vertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int num_of_vertex = 9;

    int adjm[9][9] = {
        {0, 8, 10, 3, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 6, 5, 4, 0, 0},
        {0, 0, 0, 0, 0, 5, 3, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 12},
        {0, 0, 0, 0, 7, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 11, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    for (int i = 0; i < num_of_vertex; i++) {
        for (int j = 0; j < num_of_vertex; j++) {
            if (adjm[i][j] != 0) {
                add_edge(i, j, adjm[i][j]);
            }
        }
    }

    print_adjacency_list(num_of_vertex);
    BFS(0, num_of_vertex);

    return 0;
}
