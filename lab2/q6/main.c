#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }

    int sum;
    printf("Enter the number : ");
    scanf("%d",&sum);

    int count=0;
    for(int i=0;i<n;++i){
        if(arr[i]<=sum){
            for(int j=i+1;j<n;++j){
                if(arr[j]==sum-arr[i]){
                    printf("%d %d\n",arr[i],arr[j]);
                    ++count;
                    break;
                }
            }
        }
    }
    if(count==0){
        printf("No such pair found in the array");
    }
    else printf("No. of pairs are : %d",count);

    return 3;
}
