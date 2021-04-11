#include<stdio.h>
#include<stdlib.h>
#define INFINITY 9999
#define undefined -1

struct edges{
	int src,dst,w;
};
void bellman_ford(int V,int E,struct edges *e,int src){
	int *dist=(int *)malloc(sizeof(int)*V);
	int *pred=(int *)malloc(sizeof(int)*V);
	int i,j,u,v;
	for(i=0;i<V;i++){
		dist[i]=INFINITY;
		pred[i]=undefined;
	}
	dist[src]=0;
	for(i=0;i<V-1;i++){
		for(j=0;j<E;j++){
			u=e[j].src;
			v=e[j].dst;
			if(dist[u]!=INFINITY && dist[u]+e[j].w<dist[v]){
				pred[v]=u;
				dist[v]=dist[u]+e[j].w;
			}
		}
	}
	//to check if negative weight cycle exist
	for(j=0;j<E;j++){
		u=e[j].src;
		v=e[j].dst;
		if(dist[u]!=INFINITY && dist[u]+e[j].w<dist[v]){
			printf("\nGraph Contains a Negative Weight cycle\n");
			return;
		}
	}
	for(i=0;i<V;i++){
		if(i!=src && dist[i]!=INFINITY){
			j=i;
			printf("\nDistance from %d to %d:%d",src,i,dist[i]);
			printf("\nPath:%d",j);
			do{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=src);
		}
	}
	
}
void main(){
	int V,E,i,s;
	
	struct edges t,*e;		
	printf("Enter no .of vertices:");
	scanf("%d",&V);
	printf("Enter no. of Edges:");
	scanf("%d",&E);
	e=(struct edges *)malloc(E*sizeof(struct edges));
	printf("Enter the details for each edge:");
	for(i=0;i<E;i++){
		printf("Enter source destination weight for edge %d:",i+1);
		scanf("%d %d %d",&t.src,&t.dst,&t.w);
		e[i]=t;
	}
	printf("Enter the Source Vertex:");
	scanf("%d",&s);
	bellman_ford(V,E,e,s);
}
