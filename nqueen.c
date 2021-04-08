#include<stdio.h>
#include<stdlib.h>
int ts=0;
void printsolution(int **board,int n){
	int i,j;
	char c;
	printf("\n %d Solution to place %d queens:\n",ts+1,n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			c='-';	
			if(board[i][j]==1)
				c='Q';
			printf("%c ",c);		
		}
		printf("\n");
	}
	ts=ts+1;
}
int isSafe(int **board, int n,int r,int c){
	int i,j;
	// check is someone there in same column
	for(i=0;i<r;i++){
		if(board[i][c]==1)
			return 0;
	}
	//check in lower diagonal left side
	for(i=r,j=c; i>=0 && j>=0;j--,i--){
		if(board[i][j]==1)
			return 0;
	}
	//check in lower diagonal right side
	for(i=r,j=c; i>=0 && j<n;j++,i--){
		if(board[i][j]==1)
			return 0;
	}
	return 1;
}
void solve(int **board,int n,int r){
	int i;
	if(r==n){
		printsolution(board,n);
	}
	//try all possible column
	for(i=0;i<n;i++){
		if(isSafe(board,n,r,i)){
			//place and check Queen placements
			board[r][i]=1;
			solve(board,n,r+1);
			//backtrack and find other solution
			board[r][i]=0;
		}
	}
}
void nqueen(int n){
	int **board = (int **)malloc(sizeof(int*)*n);
	int i,j;
	//allocate board
	for(i=0;i<n;i++){
		board[i]=(int *)malloc(sizeof(int)*n);
	}
	//initialize board
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			board[i][j]=0;		
		}
	}
	solve(board,n,0);
}
void main(){
	int n;
	printf("Enter the number of Queens:");
	scanf("%d",&n);
	nqueen(n);
	printf("\nnumber of possible solution=%d\n",ts);	
}
