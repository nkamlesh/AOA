#include<stdio.h>
#include<stdlib.h>
#define INFINITY 9999
#define MAX 10
#define undefined -1
  
void dijkstra(int **G,int n,int startnode)
{
 	int **cost, *visited, *pred,*distance;
 	cost=(int **)malloc(sizeof(int *)*n);
 	visited=(int *)malloc(sizeof(int)*n);
 	distance=(int *)malloc(sizeof(int)*n);
 	pred=(int *)malloc(sizeof(int)*n);
	//int cost[MAX][MAX],distance[MAX],pred[MAX];
	//int visited[MAX];
	int count,mindistance,nextnode,i,j;
	for(i=0;i<n;i++){
		 cost[i]=(int *)malloc(sizeof(int)*n);
	}
	

	//create the cost matrix
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(G[i][j]==0&&i!=j)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
		}
	}
	
	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=INFINITY;
		pred[i]=undefined;
		visited[i]=0;
	}
	
	distance[startnode]=0;
	//visited[startnode]=1;
	count=0;
	
	while(count<n-1)
	{
		mindistance=INFINITY;
		
		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
			
			//check if a better path exists through nextnode			
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
 
	//print the path and distance of each node
	printf("%d %d",undefined,startnode);
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of node%d=%d",i,distance[i]);
			printf("\nPath=%d",i);
			
			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
				if(j==undefined){
					("the graph is not connected graph. and node %d cannot be reached",i);
					break;
				}
			}while(j!=startnode);
	}
	free(distance);
	free(pred);
	free(visited);
	for(i=0;i<n;i++){
		free(cost[i]);
	}	
	free(cost);
}
int main()
{
	int **G,i,j,n,u;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	G=(int **)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++){
		G[i]=(int *)malloc(sizeof(int)*n);
	}
	printf("\nEnter the adjacency matrix (0-no egde):\n");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				G[i][j]=0;
				continue;
			}
			printf("edge between %d - %d =",i,j);
			scanf("%d",&G[i][j]);
		}
	}
	
	printf("\nEnter the starting node:");
	scanf("%d",&u);
	dijkstra(G,n,u);
	for(i=0;i<n;i++){
		free(G[i]);
	}	
	free(G);	
	return 0;
}

