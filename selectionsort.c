#include<stdio.h>
main()
{
	int a[5]={8,5,4,6,2};
	int min,i,j,temp;

	for(i=0;i<4;i++)
	{
			min=i;
		for(j=i+1;j<5;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			
			}			
    	}
	   temp=a[i];
	   a[i]=a[min];
	   a[min]=temp;		    
	}

			for(i=0;i<5;i++)
			{
				printf("%d",a[i]);
			}

	

}
