#include<stdio.h>
#include<stdlib.h>
#include "BFS1.h"
#define MAX 20

int visited[MAX];
node *G[20];          //heads of the linked list
int n;                 // no of nodes

int empty(Q *P)		//function to check whether the queue is empty or not
{
	if(P->R==-1)
		return(1);

	return(0);
}

int full(Q *P)			//function to check whether the queue is full or not
{
	if(P->R==MAX-1)
		return(1);

	return(0);
}

void enqueue(Q *P,int x)		//function to enter an element in a queue
{
	if(P->R==-1)
	{
		P->R=P->F=0;
		P->data[P->R]=x;
	}
	else
	{
		P->R=P->R+1;
		P->data[P->R]=x;
	}
}

int dequeue(Q *P)		//function to remove an element from the queue
{
	int x;
	x=P->data[P->F];
	if(P->R==P->F)
	{
		P->R=-1;
		P->F=-1;
	}
	else
		P->F=P->F+1;
	return(x);
}

void BFS(int v)		//implementing the BFS Algorithm
{
	int w,i,visited[MAX];
	Q q;

	node *p;
	q.R=q.F=-1;              //initialise
	for(i=0;i<n;i++)
		visited[i]=0;
	enqueue(&q,v);
	printf("\nVisit\t%d",v);
	visited[v]=1;
	while(!empty(&q))
	{
		v=dequeue(&q);
		//insert all unvisited,adjacent vertices of v into queue
		for(p=G[v];p!=NULL;p=p->next)
		{
			w=p->vertex;
			if(visited[w]==0)
			{
				enqueue(&q,w);
				visited[w]=1;
				printf("\nvisit\t%d",w);
			}
		}
	}
	
}
void undir_readgraph()		//function for reading undirected graph
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
}

void dir_readgraph()		//function for reading directed graph
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
}

void insert(int vi,int vj)		//function to insert an edge between two vertices
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
