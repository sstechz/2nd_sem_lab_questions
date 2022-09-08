#include <stdio.h>
#include <stdlib.h>

void swap(int *p,int *q){
    int t = *p;
    *p = *q;
    *q = t;
}

int partition(int arr[],int si,int ei){
    //last element as the pivot element
    int pivot=arr[ei];
    int i=si-1;

    for(int j=si;j<ei;++j){
        if(arr[j]<pivot){
            ++i;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[ei]);
    return (i+1);
}

void quick_sort(int arr[],int si,int ei){
    if(si<ei){
        int pi=partition(arr,si,ei);
        quick_sort(arr,si,pi-1);
        quick_sort(arr,pi+1,ei);
    }
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

    quick_sort(arr,0,n-1);
    printf("Array after sorting is : ");
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }

    return 3;
}
