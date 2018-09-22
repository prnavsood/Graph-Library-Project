/*BFS1.h*/

#ifndef _BFS1_H_
#define _BFS1_H_
#define MAX 20

typedef struct Q
{
	int data[MAX];
	int R,F;
}Q;

typedef struct node
{
	struct node *next;
	int vertex;
}node;

void enqueue(Q *,int);
int dequque(Q *);
int empty(Q *);
int full(Q *);
void dir_readgraph();      //create an adjecency list
void undir_readgraph();      //create an adjecency list
void insert(int ,int );     //insert an edge (vi,vj)in adj.list
void BFS(int);

#endif  //_BFS1_H_
