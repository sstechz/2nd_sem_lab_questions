#include <stdio.h>
#include <stdlib.h>

void insarray(int arr[],int n){
    int p,e;
    printf("Enter the position where where element to be inserted : ");
    scanf("%d",&p);
    printf("Enter the value of new element : ");
    scanf("%d",&e);

    if(p==1){
        //array size is increased by 1(ie 0...n) & !(0...n-1)
        for(int i=n;i>0;--i){
            arr[i]=arr[i-1];
        }
        arr[0]=e;
    }

    else if(p==n){
        arr[n]=e;
    }

    else{
        for(int i=n;i>=p;--i){
            arr[i]=arr[i-1];
        }
        arr[p-1]=e;
    }

    printf("\nElements after insertion are -->\n");
    for(int i=0;i<=n;++i){
        printf("arr[%d] = %d\n",i,arr[i]);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;++i){
        printf("arr[%d] = ",i);
        scanf("%d",&arr[i]);
    }
    printf("\n");

    insarray(arr,n);
    return 3;
}
