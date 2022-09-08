#include <stdio.h>
#include <stdlib.h>

void arrdelete(int arr[],int n){
	int p;
	printf("Enter the position of the element to be deleted :");
	scanf("%d",&p);

	if(p==1){
		for(int i=0;i<n-1;++i){
			arr[i]=arr[i+1];
		}
	}

	else if(p>1 && p<n){
		for(int i=p-1;i<n;++i){
			arr[i]=arr[i+1];
		}
	}
	// else if(p==n) simply decrease the array size by 1

	printf("The value of the array after deleting the %dth element : \n",p);
	for(int i=0;i<n-1;++i){
		printf("arr[%d] = %d\n",i,arr[i]);
	}
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

	arrdelete(arr,n);

	return 3;
}
