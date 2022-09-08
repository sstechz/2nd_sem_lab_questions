//  lab10 q1

#include <stdio.h>
#include <stdlib.h>

int n;

void print_list(int adj[n][n]){
    for(int i=0;i<n;++i){
        printf("%d ",i);
        for(int j=0;j<n;++j){
            if(adj[i][j]!=0){
                printf("-> %d ",j);
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

int main()
{
    printf("\n\nEnter the number of vertices in the graph : ");
    scanf("%d",&n);
    
    //  data input inside the adjacency matrix
    int Adj[n][n];
    printf("Enter the adjacency matrix of order %d*%d : \n",n,n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&Adj[i][j]);   
        }
    }
    printf("\n\nThe converted list is :- \n");
    print_list(Adj);

    return 3;
}