#include<stdio.h>
void maxsum(int a[],int n)
{
	int max_so_far,max_end_here,i;
	int start=0,end=0,s=0;
	max_so_far=a[0];
	max_end_here=0;
	for(i=0;i<n;i++)
	{
		max_end_here=max_end_here+a[i];
		if(max_so_far<max_end_here)
		{
			max_so_far=max_end_here;
			start=s,end=i;
		}
		if(max_end_here<0)
		{
			max_end_here=0;
			s=i+1;
		}
	}
	printf("%d\n",max_so_far);
	printf("%d,%d",start,end);
}
main()
{
	int a[]={3,3,9,9,5};
	 int n=5;
	 maxsum(a,n);
}
