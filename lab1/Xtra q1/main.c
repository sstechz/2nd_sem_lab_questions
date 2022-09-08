#include <stdio.h>
#include <stdlib.h>


//78 15 45 23 45 01
//find the position of 45

void insertionSort(int *p, int n){
	int i,j,key;
	for(i=1; i<n; ++i){
		j=i-1;
		key = *(p+i);

		while(j>=0 && *(p+j)>key){
			*(p+j+1) = *(p+j);
			--j;
		}
		*(p+j+1) = key;
	}

	printf("The sorted array is : ");
	for(int i=0; i<n;++i){
		printf("%d ",*(p+i));
	}
}

void binarySearch(int arr[], int ul, int ll, int e){
	int mid = (ul+ll)/2;
	if((ul == ll) && (arr[mid] != e)){
		printf("Element not found");
		return;
	}
	if (arr[mid] > e){
		ul = mid-1;
		binarySearch(arr,ul,ll,e);
	}
	if (arr[mid] < e){
		ll = mid+1;
		binarySearch(arr,ul,ll,e);
	}
	if(arr[mid] == e){
		printf("\nThe searching element is present at %dth position in the sorted array \n",mid+1);
		return;
	}

}

int main()
{
	int n;
	printf("Enter the size of the array : ");
	scanf("%d",&n);

	int arr[n];
	for(int i = 0; i<n; ++i){
		scanf("%d",&arr[i]);
	}

	insertionSort(arr,n);

	int e;
	printf("\nEnter the element to be searched : ");
	scanf("%d",&e);
	binarySearch(arr,n-1,0,e);

	return 3;
}
