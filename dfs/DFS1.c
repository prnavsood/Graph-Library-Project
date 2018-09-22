#include<stdio.h>
#include<stdlib.h>
#include "DFS1.h"
#define MAX 20

int visited[MAX];
node *G[20];          //heads of the linked list
int n;                 // no of nodes

void DFS(int i)          //function to implement the DFS algorithm
{
     node *p;
     printf("\nvisit\t%d",i);
     p=G[i];
     visited[i]=1;
     while(p!=NULL)
     {
          i=p->vertex;
          if(!visited[i])
               DFS(i);
          p=p->next;
     }
}

void dir_readgraph()          //function for reading directed graph
{
     int i,vi,vj,no_of_edges;
     printf("\nEnter no. of vertices :");
     scanf("%d",&n);
     //initialise G[] with NULL
     for(i=0;i<n;i++)
          G[i]=NULL;
     //read edges and insert them in G[]
     printf("\nEnter no of edges :");
     scanf("%d",&no_of_edges);
     for(i=0;i<no_of_edges;i++)
     {
          printf("\nEnter an edge (u,v)  :");
          scanf("%d%d",&vi,&vj);
          insert(vi,vj);
          //insert(vj,vi);
     }
     for(i=0;i<n;i++)
          visited[i]=0;
}

void undir_readgraph()        //function for reading undirected graph
{
     int i,vi,vj,no_of_edges;
     printf("\nEnter no. of vertices :");
     scanf("%d",&n);
     //initialise G[] with NULL
     for(i=0;i<n;i++)
          G[i]=NULL;
     //read edges and insert them in G[]
     printf("\nEnter no of edges :");
     scanf("%d",&no_of_edges);
     for(i=0;i<no_of_edges;i++)
     {
          printf("\nEnter an edge (u,v)  :");
          scanf("%d%d",&vi,&vj);
          insert(vi,vj);
          insert(vj,vi);
     }
     for(i=0;i<n;i++)
          visited[i]=0;
}

void insert(int vi,int vj)         //function to insert an edge between two vertices
{
     node *p,*q;
     //acquire memory for the new node
     q=(node *)malloc(sizeof(node));
     q->vertex=vj;
     q->next=NULL;
     //insert the node in the linked list for the vertex no. vi
     if(G[vi]==NULL)
          G[vi]=q;
     else
     {
          // go to the end of linked list
          p=G[vi];
          while(p->next!=NULL)
               p=p->next;
          p->next=q;
     }
}
