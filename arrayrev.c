#include <stdio.h>
#include <stdlib.h>

void reverse_array(int *p,int n){
    for(int i=0;i<n/2;++i){
        int temp = *(p+i);
        *(p+i)=*(p+n-1-i);
        *(p+n-1-i)=temp;
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

    reverse_array(arr,n);
    printf("The reversed array is : ");
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }printf("\n\n");
    
    return 3;
}