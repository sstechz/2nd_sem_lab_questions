#include <stdio.h>
#include <stdlib.h>

void print_matrix(int matrix[7][7]){
    for(int i=0;i<7;++i){
        for(int j=0;j<7;++j){
            printf("%d ",matrix[i][j]); 
        }
        printf("\n");
    }
}

void create_edge(int **mat,int a,int b){
    mat[a][b]=1;
    return;
}

int main()
{
    //  here we are using a graph with 7 nodes 
    int matrix[7][7]={0};
    int *adj=&matrix;

    create_edge(adj,0,1);

    print_matrix(matrix);

    return 3;
}