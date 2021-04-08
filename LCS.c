/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
int max(int a, int b);
struct stack{
    char s[MAX];
    int top;
};
struct stack s1;

void printseq(char **d,char *x, int m, int n){
    int i=m,j=n;
    while(i>0 &&j>0){
        if(d[i][j]=='d'){
            s1.s[++s1.top]=x[i-1];
            i=i-1;
            j=j-1;
        }
        else if(d[i][j]=='u'){
            i=i-1;
        }
        else{
            j=j-1;
        }
    }
    printf("\n Longest common Sub-Sequence:");
    while(s1.top>-1){
        printf("%c",s1.s[s1.top--]);
    }
}
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *x, char *y, int m, int n )
{
   /*int c[MAX][MAX];
   char d[MAX][MAX];*/
   int **c;
   char **d;
   int i,j;
   c=(int **)malloc(sizeof(int *) * (m+1));
   d=(char **)malloc(sizeof(char *) * (m+1));
   for(i=0;i<=m;i++){
   	c[i]=(int *)malloc(sizeof(int)*(n+1));
   	d[i]=(char *)malloc(sizeof(char)*(n+1));
   }
   for(i=0;i<=m;i++){
       c[i][0]=0;
   }
   for(j=0;j<=n;j++){
       c[0][j]=0;
   }
   
   for(i=1;i<=m;i++){
       for(j=1;j<=n;j++){
           if(x[i-1]==y[j-1]){
               c[i][j]=1+c[i-1][j-1];
               d[i][j]='d';
           }
           else if(c[i-1][j]>=c[i][j-1]){
               c[i][j]=c[i-1][j];
               d[i][j]='u';
           }
           else{
               c[i][j]=c[i][j-1];
               d[i][j]='l';
           }
       }
   }
   for(i=1;i<=m;i++){
       for(j=1;j<=n;j++){
           printf("%2d ",c[i][j]);
       }
       printf("\n");
   }
   i=c[m][n];
   printseq(d,x,m,n);
   for(j=0;j<=m;j++){
   	free(c[j]);
   	free(d[j]);
   }   
   free(c);
   free(d);
   return i;
}
  
/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a >= b)? a : b;
}
  
/* Driver program to test above function */
int main()
{
  char x[MAX];
  char y[MAX];
  s1.top=-1;
  printf("Enter the String-X:");
  scanf("%s",x);
  printf("Enter the String-Y:");
  scanf("%s",y);
  int m = strlen(x);
  int n = strlen(y);
  
  printf("\n Length of LCS is %d\n", lcs( x, y, m, n ) );
    
  return 0;
}

