// C Program for Floyd Warshall Algorithm
#include<stdio.h>
#include<stdlib.h>
#define INF 99999

// A function to print the solution matrix
void printSolution(int **dist,int V);

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall (int **graph,int V)
{
	/* dist[][] will be the output matrix
	that will finally have the shortest
	distances between every pair of vertices */
	int **dist, i, j, k;
	dist=(int **)malloc(sizeof(int *)*V);
	for(i=0;i<V;i++){
		dist[i]=(int *)malloc(sizeof(int)*V);
	}
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	for (k = 0; k < V; k++)
	{
		// Pick all vertices as source one by one
		for (i = 0; i < V; i++)
		{
			// Pick all vertices as destination for the
			// above picked source
			for (j = 0; j < V; j++)
			{
				// If vertex k is on the shortest path from
				// i to j, then update the value of dist[i][j]
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	

	// Print the shortest distance matrix
	printSolution(dist,V);
	for(i=0;i<V;i++){
		free(dist[i]);
	}
	free(dist);
}

/* A utility function to print solution */
void printSolution(int **dist,int V)
{
	printf ("The following matrix shows the shortest distances"
			" between every pair of vertices \n");
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				printf("%7s", "INF");
			else
				printf ("%7d", dist[i][j]);
		}
		printf("\n");
	}
}


// driver program to test above function
int main()
{
	int **g,i,j,n;
	printf("enter the number of vertices:");
	scanf("%d",&n);
	g=(int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++){
		g[i]=(int *)malloc(sizeof(int)*n);
	}
	printf("Enter the Adjacency Matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				g[i][j]=0;
				continue;
			}
			printf("Enter weight of edge between %d and %d (0-if edge does not exist):",i,j);
			scanf("%d",&g[i][j]);
			if(g[i][j]==0){
				g[i][j]=INF;
			}
		}
	}
	// Print the solution
	floydWarshall(g,n);

	for(i=0;i<n;i++){
		free(g[i]);
	}
	free(g);
	return 0;
}

