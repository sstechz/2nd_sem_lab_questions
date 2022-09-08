#include <stdio.h>
#include <stdlib.h>

void forward(int arr[],int n){
	for(int i=0;i<n;++i){
		printf("arr[%d] = %d\n",i,arr[i]);
	}
	printf("\n");
}

void reverse(int arr[],int n){
	for(int i=n-1;i>=0;--i){
		printf("arr[%d] = %d\n",i,arr[i]);
	}
	printf("\n");
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
	printf("\n");

	forward(arr,n);
	reverse(arr,n);

	return 3;
}
