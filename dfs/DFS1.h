/*DFS1.h*/
#ifndef _DFS1_H_
#define _DFS1_H_

typedef struct node
{
     struct node *next;
     int vertex;
}node;

void dir_readgraph();         //create an adjecency list
void undir_readgraph();      //create an adjecency list
void insert(int ,int );     //insert an edge (vi,vj)in adj.list
void DFS(int i);

#endif // _DFS1_H_
