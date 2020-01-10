#include<stdio.h>
/*
int fibo(int n)
{
	if(n==0)
	return 0;
	else if(n==1)
	return 1;
	else
	return fibo(n-1)+fibo(n-2);
}
main()
{
	int n=4,i;
	for(i=0;i<=n;i++)
	printf("%d ",fibo(i));
}
*/
int honoi(int n)
{
	if(n==1)
	{
		return 1;
	}
	else
	{
		return 2*honoi(n-1)+1;
	}
}
main()
{
	int n=3;
	printf("%d",honoi(n));
}
