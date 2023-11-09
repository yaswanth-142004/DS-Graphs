#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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
        printf("for V%d", i+1 );
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
int minkey(int num_of_vertex,int key[],bool visited[])
{
    int min = INT_MAX, min_index;
    for(int v=0;v<num_of_vertex;v++)
    {
        if(visited[v]==false && key[v]<min)
        {
            min = key[v],min_index=v;
        }
    }
    return min_index;

}

void print_MST_using_prims(int num_of_vertex,int adjm[9][9])
{
    bool visited[num_of_vertex];
    int key[num_of_vertex];
    int MST[num_of_vertex];
    for(int i=0;i<num_of_vertex;i++)
    {
        visited[i] = false;
        key[i]  = INT_MAX;

    }
    key[0]=0;
    MST[0]=-1;
    for(int count = 0 ; count< num_of_vertex-1;count++)
    {
        int u = minkey(num_of_vertex,key,visited);
        visited[u]=true;
    
    for(int v=0; v<num_of_vertex;v++)
    {
        if(adjm[u][v] && visited[v]==false && adjm[u][v]<key[v])
        {
            MST[v] = u, key[v] = adjm[u][v];
        }
    }
    }
    printf("Edge\tWeight\n");
    for(int i=1;i<num_of_vertex;i++)
    {
        printf("%d - %d \t%d \n",MST[i],i,adjm[i][MST[i]]);
    }
}

int main() {
    int num_of_vertex = 9;

    int adjm[9][9] = {
        {0, 8, 10, 3, 0, 0, 0, 0, 0},
        {8, 0, 0, 0, 6, 5, 4, 0, 0},
        {10, 0, 0, 0, 0, 5, 3, 0, 0},
        {3, 0, 0, 0, 0, 0, 4, 2, 0},
        {0, 6, 0, 0, 0, 0, 0, 0, 12},
        {0, 5, 0, 0, 7, 0, 1, 0, 0},
        {0, 4, 3, 4, 0, 1, 0, 11, 1},
        {0, 0, 1, 0, 0, 0, 11, 0, 0},
        {0, 0, 0, 0, 0, 12, 1, 0, 0}

    };

    for (int i = 0; i < num_of_vertex; i++) {
        for (int j = 0; j < num_of_vertex; j++) {
            if (adjm[i][j] != 0) {
                add_edge(i, j, adjm[i][j]);
            }
        }
    }

      print_adjacency_list(num_of_vertex);
      print_MST_using_prims(num_of_vertex,adjm);
      return 0;
}
