#include<stdio.h>
#include "BFS1.h"
void main()
{
     int i,op;
     printf("\n!!!!!!ATTENTION!!!!!!");
     printf("\nPlease enter the vertices starting from '0' ");
     do
     {
          printf("\n\n1)Create a directed graph\n2)Create an undirected graph\n3)Apply the BFS Algorithm\n4)Quit");
          printf("\nEnter Your Choice: ");
          scanf("%d",&op);
          switch(op)
          {
               case 1:
                    dir_readgraph();
               break;

               case 2:
                    undir_readgraph();
               break;

               case 3:
                    printf("\nStarting Node No. : ");
                    scanf("%d",&i);
                    BFS(i);
               break;
          }
     }while(op!=4);
}
