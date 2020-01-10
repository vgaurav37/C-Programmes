#include<stdio.h>
main()
{
	int a[15]={7,3,5,4,2,6,10,8,9,11,2};
	int i,j,key,n=11;
	for(i=1;i<n;i++)
	{
	    	key=a[i];
	    	j=i-1;
	      while(j>=0&&a[j]>key)
	       {
	       	  a[j+1]=a[j];
	       	  j--;
	       	 
		   }
		   a[j+1]=key;
	}
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
