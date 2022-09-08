#include <stdio.h>
#include <stdlib.h>

void clockwise_rotate(int *q,int n){
    int k;
    printf("Enter the no of position to be shifted by (i.e. clockwise shift) : ");
    scanf("%d",&k);

    for(int i=0;i<k;++i){
        int temp=*(q+n-1);
        for(int j=n-1;j>=1;--j){
            *(q+j)=*(q+j-1);
        }
        *q=temp;
    }
}

void anticlockwise_rotate(int *p,int n){
    int k;
    printf("Enter the no of position to be shifted by (i.e. anticlockwise shift) : ");
    scanf("%d",&k);

    for(int i=0;i<k;++i){
        int temp=*p;
        for(int j=0;j<n-1;++j){
            *(p+j)=*(p+j+1);
        }
        *(p+n-1)=temp;
    }

}

//function for printing array elements
void print_arr(int arr[],int n){
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }printf("\n\n");
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

    int choice=0;
    printf("Enter 1 for clockwise rotation & -1 for anticlockwise rotation : ");
    scanf("%d",&choice);

    if(choice == 1){
        clockwise_rotate(arr,n);
        printf("Array after clockwise rotation : ");
        print_arr(arr,n);
    }
    else{
        anticlockwise_rotate(arr,n);
        printf("Array after anticlockwise rotation : ");
        print_arr(arr,n);
    }
    return 3;
}
