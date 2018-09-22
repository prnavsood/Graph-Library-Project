/*bellfo.h*/
#ifndef _bellfo_H_
#define _bellfo_H_
struct Edge
{
    // This structure is equal to an edge.These edges are directed edges. 
    //so they contain source and destination and some weight.
    int source, destination, weight;
};

// a structure to represent a connected, directed and weighted graph
struct Graph
{
    int V, E;
    // V is number of vertices and E is number of edges

    struct Edge* edge;
    // This structure contain another structure which we already created edge.
};
struct Graph* createGraph(int, int);
void FinalSolution(int *dist, int n);
void BellmanFord(struct Graph* graph, int);
#endif  //_bellfo_H_
