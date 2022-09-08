#include <stdio.h>
#include <stdlib.h>

void swap(int *p,int *q){
    int temp=*p;
    *p=*q;
    *q=temp;
}

int partition(int arr[],int si,int ei){
    int pivot = arr[ei];
    int i=si-1;

    for(int j=si;j<ei;++j){
        if(arr[j]<pivot){
            ++i;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[i+1],&arr[ei]);
    return (i+1);
}

void quicksort(int arr[],int si,int ei){
    if(si<ei){
        int pi=partition(arr,si,ei);

        quicksort(arr,si,pi-1);
        quicksort(arr,pi+1,ei);
    }
}

int main()
{
    int arr[]={7,4,6,5,9};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Before sort : ");
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }printf("\n\n");

    quicksort(arr,0,n-1);
    printf("After sort : ");
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }printf("\n\n");


    return 3;
}














// #include <stdio.h>
// #include <stdlib.h>

// void merge(int arr[],int si,int mid,int ei){
//     int m=mid-si+1;
//     int n=ei-mid;

//     int a1[m];
//     int a2[n];

//     for(int i=0;i<m;++i){
//         a1[i]=arr[si+i];
//     }
//     for(int i=0;i<n;++i){
//         a2[i]=arr[mid+1+i];
//     }

//     int i=0;
//     int j=0;
//     int k=si;

//     while(i<m && j<n){
//         if(a1[i]<a2[j]){
//             arr[k]=a1[i];
//             ++i;
//         }
//         else{
//             arr[k]=a2[j];
//             ++j;
//         }
//         ++k;
//     }
//     while(i<m){
//         arr[k]=a1[i];
//         ++i;
//         ++k;
//     }
//     while(j<n){
//         arr[k]=a2[j];
//         ++j;
//         ++k;
//     }

// }

// void mergesort(int arr[],int si,int ei){
//     if(si<ei){
//         int mid=si+(ei-si)/2;

//         mergesort(arr,si,mid);
//         mergesort(arr,mid+1,ei);

//         merge(arr,si,mid,ei);
//     }
    

// }

// int main()
// {
//     int arr[]={8,4,6,2,7};
//     int n=5;
//     printf("Before sort : ");
//     for(int i=0;i<n;++i){
//         printf("%d ",arr[i]);
//     }printf("\n\n");

//     mergesort(arr,0,n-1);
//     printf("After sort : ");
//     for(int i=0;i<n;++i){
//         printf("%d ",arr[i]);
//     }printf("\n\n");

//     return 3;
// }