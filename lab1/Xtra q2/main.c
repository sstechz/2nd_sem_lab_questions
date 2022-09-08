#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m,n;
	printf("Row of 2D array : ");
	scanf("%d",&m);
	printf("Column of 2D array : ");
	scanf("%d",&n);

	int arr[m][n];
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			scanf("%d",&arr[i][j]);
		}
	}

	int e;
	printf("Enter the element to be searched : ");
	scanf("%d",&e);

	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			if(e == arr[i][j]){
				printf("\nThe searching element is present at\nRow : %d\nColumn : %d\n\n",i+1,j+i);
				return 3;
			}
		}
	}
	printf("Element not found\n");
	return 3;
}
