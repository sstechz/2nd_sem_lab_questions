#include <stdio.h>
#include <stdlib.h>

void arrsearch(int arr[],int n){
	int e;
	printf("\nEnter the element to be searched : ");
	scanf("%d",&e);

	for(int i=0;i<n;++i){
		if(arr[i]==e){
			//returning the position of the array element
			printf("%d is present at %dth position \n",e,i+1);
			return;
		}
	}

	printf("Element not found\n");
	return;
}

int main()
{
	int n;
	printf("Enter the size of the array : ");
	scanf("%d",&n);

	int arr[n];
	for(int i=0;i<n;++i){
		printf("arr[%d] = ",i);
		scanf("%d",&arr[i]);
	}

	arrsearch(arr,n);

	return 3;
}
