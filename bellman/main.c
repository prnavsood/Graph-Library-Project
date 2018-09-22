#include<stdio.h>
#include "bellfo.h"
int main()
{
    int V,E,S;  //V = no.of Vertices, E = no.of Edges, S is source vertex

    printf("\n!!!!!!ATTENTION!!!!!!");
    printf("\nPlease enter the vertices starting from '0' \n");

    printf("Enter number of vertices in graph\n");
    scanf("%d",&V);

    printf("Enter number of edges in graph\n");
    scanf("%d",&E);

    printf("Enter your source vertex number\n");
    scanf("%d",&S);

    struct Graph* graph = createGraph(V, E);    //calling the function to allocate space to these many vertices and edges

    int i;
    for(i=0;i<E;i++){
        printf("\nEnter edge %d properties Source, destination, weight respectively\n",i+1);
        scanf("%d",&graph->edge[i].source);
        scanf("%d",&graph->edge[i].destination);
        scanf("%d",&graph->edge[i].weight);
    }

    BellmanFord(graph, S);
    //passing created graph and source vertex to BellmanFord Algorithm function
 return 0;
}
