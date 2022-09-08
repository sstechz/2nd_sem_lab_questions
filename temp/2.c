//  lab10 q2

#include<stdio.h>
#define v 7

void Intial(int matrix[][v]){
    for(int i=0; i<v; i++){
    for(int j=0; j<v; j++){
        matrix[i][j]=0;
    }
}
}
void AddEdge(int matrix[][v],int i,int j){
 matrix[i][j]=1;
 matrix[j][i]=1;
}
void display(int matrix[][v]){
for(int i=0; i<v; i++){
    for(int j=0; j<v; j++){
        printf("%d ",matrix[i][j]);
    }
    printf("\n");
}

}
int main(){
    int matrix[v][v];
    Intial(matrix);
    AddEdge(matrix,0,1);
    AddEdge(matrix,0,3);
    AddEdge(matrix,0,4);
    AddEdge(matrix,1,2);
    AddEdge(matrix,1,5);
    AddEdge(matrix,2,3);
    AddEdge(matrix,2,4);
    AddEdge(matrix,3,5);
    AddEdge(matrix,4,5);
    AddEdge(matrix,4,6);
    AddEdge(matrix,5,6);
    display(matrix);
    return 0;
}