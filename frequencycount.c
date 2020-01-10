#include<stdio.h>

void frequency(int n)
{
	
	     int a[100],r,i=0,c=0,count1=0;
	     int temp=n;
	     while(n>0)
	     {
	     	a[i]=n%10;
	     	i++;
	     	n=n/10;
	     	c++;
		 }
		 printf("%d\n",c);
		 n=temp;
	     for(i=0;i<c;i++)
	     {
	     	if(a[i]!=0&&n%a[i]==0)
	     	{
	     		
	     		count1++;
			 }
		 }
          printf("%d\n",count1);
		
	
}


main()
{
	int n=123456789;
	frequency(n);
}
