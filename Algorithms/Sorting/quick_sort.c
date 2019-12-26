#include <stdio.h>
// The leftmost element in each partition is considered to be the pivot
int partition(int* arr,int start,int end)   //function for putting the elements iin its correct position according to the pivot
{
    int pivindex = start;
    int piv = arr[end];
    int temp;
    for(int i=start;i<end;i++)
    {
        if(arr[i]<piv)
        {
            temp = arr[pivindex];
            int num1 = arr[i];
            arr[pivindex] = num1;
            arr[i] = temp;
            pivindex++;
        }
    }
    temp = arr[end];
    arr[end] = arr[pivindex];
    arr[pivindex] = temp;
    return pivindex;
}
void quicksort(int* arr,int start,int end)  //Main function for doing quicksort
{
    if(start < end)
    {
       int pivot=partition(arr,start,end);
       quicksort(arr,start,pivot-1);
       quicksort(arr,pivot+1,end);
       
    }
    else
    {
        return;
    }
}
int main(void) {
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    scanf("%d",&arr[i]);
	    
	}
	quicksort(arr,0, n-1);
	for(int i=0;i<n;i++)
	{
	    printf("%d\n",arr[i]);
	    
	}
	return 0;
}
