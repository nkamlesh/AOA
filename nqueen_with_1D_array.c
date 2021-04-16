#include<stdio.h>
#include<stdlib.h>
int ts=0;
int tc=0;
void printsolution(int *board,int n){
	int i,j;
	char c;
	printf("\n %d Solution to place %d queens:\n",ts+1,n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			c='-';
			if(board[i]==j)
				c='Q';
			printf("%c ",c);		
		}
		printf("\n");
	}
	ts=ts+1;
}
int isSafe(int *board, int n,int r,int c){
	int i,j;
    // check is someone there in same column
	for(i=0;i<r;i++){
		if(board[i]==c)
			return 0;
	}
	//check in diagonal
    for(i=0;i<r;i++){
        if(abs(board[i]-c)==abs(r-i)){
            return 0;        
        }
    }
    
	return 1;
}
void solve(int *board,int n,int r){
	int i;
	if(r==n){
		printsolution(board,n);
       // printf("Efforts to place 8 queens:%d",tc);
        //exit(0);
	}
	//try all possible column
	for(i=0;i<n;i++){
		if(isSafe(board,n,r,i)){
			//place and check Queen placements
			board[r]=i;
			solve(board,n,r+1);
			//backtrack and find other solution
			board[r]=-1;
		}
	}
}
void nqueen(int n){
	int *board = (int *)malloc(sizeof(int)*n);
	int i,j;
	//initialize board
	for(j=0;j<n;j++){
		board[j]=-1;		
	}
    for(i=0;i<n;i++){
        printf("%d ",board[i]);   
    }
    printf("\n");
	solve(board,n,0);
}
void main(){
	int n;
	printf("Enter the number of Queens:");
	scanf("%d",&n);
	nqueen(n);
	printf("\nnumber of possible solution=%d\n",ts);	
}
