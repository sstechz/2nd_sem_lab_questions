//INSERTION SORTING

#include <stdio.h>
#include <stdlib.h>

void printarray(int array[],int n){
    for(int i=0;i<n;++i){
        printf("array[%d] = %d\n",i,array[i]);
    }
}

void sort(int array[],int n){
    int i,j,temp;
    for(i=1;i<n;++i){
        j=i-1;
        temp=array[i];

        //inner loop for comparing the elements of sorted part
        while(j>=0 && array[j]>temp){
            array[j+1]=array[j];
            j=j-1;
        }

        //if while becomes false then assigning value of the last vacant element 
        array[j+1]=temp;        
    }
    printf("The value of the array elements after sorting is =>\n");
    printarray(array,n);

}

int main()
{
    int arr[]={8,7,3,2,4,9};
    int n = sizeof(arr)/sizeof(int);
    printf("the initial value of the array is : \n");
    printarray(arr,n);
    sort(arr,n);

    return 3;
}