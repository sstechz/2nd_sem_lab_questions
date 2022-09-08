#include <stdio.h>
#include <stdlib.h>

void sort(int *p,int n){
    for(int j=0;j<n-1;++j){
        int min=j;
        for(int i=j;i<n;++i){
            if(*(p+min)>*(p+i)) min=i;
        }
        swap_func(&*(p+min),&*(p+j));
    }
}

void swap_func(int *p1,int *p2){
    int temp=*p1;
    *p1=*p2;
    *p2=temp;
}

void find_func(int *p,int n,int k){
    printf("\nThe %dth smallest element is : %d\n",k,*(p+k-1));
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

    int k;
    printf("Enter the kth smallest number : ");
    scanf("%d",&k);

    sort(arr,n);
    find_func(arr,n,k);

    return 3;
}
