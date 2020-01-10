 #include<stdio.h>
void merge(int a[],int,int,int);
void mergesort(int a[],int low,int high)
{
    
  
    int mid;
    if(low<high)
	{
		
		int mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
	
void merge(int a[],int low,int mid,int high)
{
	
	int n1=mid-low+1;
	int n2=high-mid;
	int i,j;
    int l1[n1],l2[n2];
    for( i=0;i<n1;i++)
    {
    	l1[i]=a[low+i];
	}
	for( j=0;j<n2;j++)
    {
    	l2[j]=a[mid+1+j];
	}
    i=0,j=0;int k=low;
	while(i<n1&&j<n2)
	{
		if(l1[i]<=l2[j])
		{
			a[k]=l1[i];
			i++,k++;
		}
		else
		{
			a[k]=l2[j];
			j++,k++;
		}	
		
	}
	while(i<n1)
	{
	  a[k]=l1[i];
	  i++,k++;
    }
	while(j<n2)
	 	{
	    a[k]=l2[j];
	    j++,k++;
       }
}
void printArray(int a[], int n) 
{ 
    int i; 
    for (i=0; i <n; i++) 
        printf("%d\t", a[i]); 
    
} 
main()
{
	int a[]={2,4,1,6,8,5,3,7};
	int n=8;
	mergesort(a,0,n-1);
	printArray(a,n);
}
