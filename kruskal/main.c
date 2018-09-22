#include<stdio.h>
#include "kruskal.h"
int main()
{
    int V,E,S;  //V = no.of Vertices, E = no.of Edges, S is source vertex
    printf("\n!!!!!!ATTENTION!!!!!!");
    printf("\nPlease enter the vertices starting from '0' \n");

    printf("Enter number of vertices in graph\n");
    scanf("%d",&V);

    printf("Enter number of edges in graph\n");
    scanf("%d",&E);

    struct Graph* graph = createGraph(V, E);    //calling the function to allocate space to these many vertices and edges

    int i;
    for(i=0;i<E;i++){
        printf("\nEnter edge %d properties Source, destination, weight respectively\n",i+1);
        scanf("%d",&graph->edge[i].src);
        scanf("%d",&graph->edge[i].dest);
        scanf("%d",&graph->edge[i].weight);
    }
    KruskalMST(graph);
 return 0;
}
