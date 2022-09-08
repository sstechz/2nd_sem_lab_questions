#include <stdio.h>
#include <stdlib.h>

void swap(int *p,int *q){
    int temp=*p;
    *p=*q;
    *q=temp;
}

void print_array(int arr[],int n){
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }printf("\n\n");
}

void reverse_array(int arr[],int n){
    for(int i=0;i<n/2;++i){
        swap(&arr[i],&arr[n-1-i]);
    }
    printf("\nThe array after reversing is : ");
    print_array(arr,n);
}

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }

    reverse_array(arr,n);

    return 3;
}
