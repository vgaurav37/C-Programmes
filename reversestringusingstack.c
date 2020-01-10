#include<stdio.h>
#include<string.h>
#define CAPACITY 20
int stack[CAPACITY];
int top=-1;
char a[20];
void pop()
{
	if(top==-1)
	{
		printf("stack is empty");
	}
	else
	{
		top--;
	}
}
char peek()
{
	
    char ele= stack[top];
    return ele;

}
void push()
{
	int i;
	printf("Enter the stirng:");
	scanf("%s",a);
	int len=strlen(a);
	//push array char in stack..
	for(i=0;i<len;i++)
	{
		top++;
		stack[top]=a[i];
	}
	
	for(i=0;i<len;i++)
	{
	     a[i]=peek();
		 pop();	
	}
	      
}
void reverse()
{
	int i;
	for(i=0;i<strlen(a);i++)
	{
		printf("%c",a[i]);
	}
	printf("\n");
}

main()
{
	int ch;
	while(1)
	{
		printf(" 1.GiveString\n 2.reverse\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
			       break;
			case 2:reverse();
			       break;
			default:printf("invalid choice");
		}
	}
}
