#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/*
 * Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.
*/

// Definition for a node:
struct Node {
    int val; 
    int numNeighbors; 
    struct Node** neighbors; 
}; 

typedef struct Node node;

// list of node pointers
node **traverse(node *s){
    int *visited = (int *)malloc(sizeof(int) * 120);
    return NULL;
}


struct Node *cloneGraph(struct Node *s) {
    struct clone;
    
    return NULL;
}
