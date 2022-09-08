//rotation of the array

#include <stdio.h>
#include <stdlib.h>

void rotarray(int arr[],int n){
    int p;
    printf("Enter the position to be rotated with : ");
    scanf("%d",&p);
    /*p represents the position to be rotated*/
    while(p--){
        int temp=arr[n-1];
        for(int i=n-1;i>0;--i){
            arr[i]=arr[i-1];
        }
        arr[0]=temp;
    }

    printf("\nThe value of the rotated array is -->\n");
    for(int i=0;i<n;++i){
        printf("arr[%d] = %d\n",i,arr[i]);
    }
}

int main()
{
    int i,n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);

    int arr[n];
    for(i=0;i<n;++i){
        printf("arr[%d] = ",i);
        scanf("%d",&arr[i]);
    }

    rotarray(arr,n);

    return 3;
}