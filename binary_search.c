#include<stdio.h>
#include<stdlib.h>
int no_of_comp;
void binary_search(int *a,int b,int e,int key){
	int m;
	
	if(b<=e){
		no_of_comp=no_of_comp+1;
		m=(b+e)/2;
		if(a[m]==key){
			printf("\nElement found at %d location",m);
			return;
		}
		else if(a[m]<key){
			b=m+1;
		}
		else{
			e=m-1;
		}
		binary_search(a,b,e,key);
	}
	else{
		printf("\nElement not found");
			
	}
}
void main(){
	int n,*a,i,key;
	no_of_comp=0;
	printf("enter the no of elements:");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		printf("enter element %d:",i);
		scanf("%d",&a[i]);
	}
	printf("\nenter the key to searched:");
	scanf("%d",&key);
	binary_search(a,0,n-1,key);
	printf("\nNo of comparision required:%d\n",no_of_comp);
}
