/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define MAX 50
struct ITEM{
    float p,w;
    float p_by_w;
};
int main()
{
    struct ITEM item[MAX],temp;
    int n,i,j,min,W;
    
    float pa=0,wa=0;
    printf("enter the no f items:");
    scanf("%d",&n);
    //reading
    for(i=0;i<n;i++){
        printf("Enter price:");
        scanf("%f",&item[i].p);
        printf("Enter weight:");
        scanf("%f",&item[i].w);
        item[i].p_by_w=item[i].p/item[i].w;
    }
    printf("Enter capacity of knapsack:");
    scanf("%d",&W);
    //sorting part
    for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(item[i].p_by_w<item[j].p_by_w){
                min=j;
            }
        }
        if(min!=i){
            temp=item[i];
            item[i]=item[min];
            item[min]=temp;
        }
    }
    printf("item no - profit weight p_by_w\n");
    for(i=0;i<n;i++){
        printf("%d - %f %f %f \n",i,item[i].p,item[i].w,item[i].p_by_w);
    }
    
    i=0;
    printf("Items Added:");
    // iterating through items
    while(wa<W){
        if(item[i].w+wa<=W){
            wa=wa+item[i].w;
            pa=pa+item[i].p;
            printf("%d ",i);
        }
        else{
           
           pa=pa+(item[i].p_by_w)*(W-wa);
           wa=wa+(W-wa);
           printf("%d ",i);
        }
        i++;
    }
    printf("\n Profit earned=%f",pa);
    return 0;
}

