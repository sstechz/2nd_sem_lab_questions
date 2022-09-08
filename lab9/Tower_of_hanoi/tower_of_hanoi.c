#include <stdio.h>

int count=0;
void tower_of_hanoi(int n,char source,char destination,char intermediate){
    if(n==1){
        printf("\nMoved disc %d from %c to %c\n",n,source,destination);
        ++count;
        return;
    }
    else{
        tower_of_hanoi(n-1,source,intermediate,destination);
        printf("\nMoved disc %d from %c to %c\n",n,source,destination);
        ++count;
        tower_of_hanoi(n-1,intermediate,destination,source);
    }
}

int main(){

    int n;
    printf("Enter the number of discs : ");
    scanf("%d",&n);

    //  Here 
    //  A -> source
    //  B -> intermediate
    //  C -> destination
    
    tower_of_hanoi(n,'A','C','B');
    printf("\n\nTotal no of moves : %d\n",count);

    return 3;
}