//write the program to rotate an array by n positions

#include <stdio.h>
#include <stdlib.h>

void arr_rotate(int *ptr,int n,int p){
    for(int i=0;i<p;++i){
        int temp=*(ptr+n-1);
        for(int j=1;j<n;++j){
            *(ptr+n-j)=*(ptr+n-j-1);
        }
        *(ptr)=temp;
    }
}

int main()
{
    int n,p;
    printf("Enter the size of the array : ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }

    printf("\nEnter the position to be rotated with : ");
    scanf("%d",&p);

    arr_rotate(arr,n,p);

    printf("\nThe rotated array is : ");
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }printf("\n\n");

    return 3;
}