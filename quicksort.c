#include<stdio.h>
int partition(int a[],int start,int end)
{
	int pivot,PIndex,i;
	pivot=a[end];
	PIndex=start;
	int temp=0;
	for(i=start;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			temp=a[i];
			a[i]=a[PIndex];
			a[PIndex]=temp;
			PIndex++;
		}
	}
	
	temp=a[PIndex];
	a[PIndex]=a[end];
	a[end]=temp;
	
return PIndex;
	
}
void quicksort(int a[],int start,int end)
{
	
	if(start<end)
	{
	   int PIndex=partition(a,start,end);
		quicksort(a,start,PIndex-1);
		quicksort(a,PIndex+1,end);
	}
   
}
main()
{
	int a[]={7,2,1,6,8,5,3,4},n=8;
	int start=0,end=n-1,i;
	quicksort(a,start,end);
    for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	
}
