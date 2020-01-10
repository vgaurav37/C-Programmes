#include<stdio.h>
main()
{
   int a[20],i,n;
   int key=6,found=0;
   int low,high,mid;
   printf("enter size:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
   	scanf("%d",&a[i]);
   }
   low=0,high=n-1;
   while(low<=high)
   {
           mid=(low+high)/2;
           if(key<a[mid])
              {
   	             high=mid-1;
              }
           else if(key>a[mid])
              {
             	low=mid+1;
	          }
	       else if(key==a[mid])
	          {
		    	printf("found at index:%d",mid);
			    found=1;
		     	break;
              }
    }
   if(!found)
	 {
		printf("not found");
	 }
}

   
