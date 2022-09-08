#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[],int n){
	int i,j,temp;
    for(i=1;i<n;++i){
        j=i-1;
        temp=arr[i];

        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j=j-1;
        }

        arr[j+1]=temp;
    }
    printf("The value of the array elements after sorting is =>\n");
    for(i=0;i<n;++i){
		printf("arr[%d] = %d\n",i,arr[i]);
	}
}

int main()
{
	int n;
	printf("Enter the size of the array :");
	scanf("%d",&n);

	int arr[n];
	for(int i=0;i<n;++i){
		printf("arr[%d] = ",i);
		scanf("%d",&arr[i]);
	}

	insertion_sort(arr,n);

	return 3;
}
