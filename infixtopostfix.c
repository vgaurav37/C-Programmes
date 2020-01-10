//program to infix to postfix...
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CAPACITY 20
char stack[CAPACITY];
int top=-1;
void push(char a)
{
	int i;
	if(top>=CAPACITY-1)
	{
		printf("stack is full:");
	}
	else
	{
		top++;
		stack[top]=a;
	
	}
}
char pop()
{
	char x=stack[top];
	top--;
	return x;
}
int is_operator(char a)
{
	if(a=='^' || a=='/' || a=='*' || a=='+' || a=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int preecedence(char b)
{
	if(b=='^')
	{
		return 3;
	}
	else if(b=='*' || b=='/')
	{
		return 2;
	}
	else if(b=='+'||b=='-')
	{
		return 1;
	}
	else
	  return 0;

}
main()
{
   int i=0,k=0;
   char  infix[50],postfix[50],temp,item;
   printf("Enter expression:");
   scanf("%s",infix);
   while(infix[i]!='\0')
   {
   	    item=infix[i];
   	    if(item=='(')
   	    {
   	         push(item);
		}
   	    if(item>='A'&& item<='Z'||item>='a'&& item<='z')
   	    {
   	    	  postfix[k]=item;
   	    	  k++;
		}
		else if(is_operator(item)==1)
		{
			  temp=pop();
			  while(is_operator(temp)==1&&preecedence(temp)>=preecedence(item))
			  {
			  	
			  	    postfix[k]=temp;
			  	    k++;
			  	    temp=pop();	   
			  }
			  push(temp);
			  push(item);
			  
		}
		else if(item==')')
		{
			temp=pop();
			while(temp!='(')
			{
				postfix[k]=temp;
				k++;
				temp=pop();
			}
		}
		i++;
		 
   }
   while(top>-1)
   {
   	  postfix[k]=pop();
   	  k++;
   }
   postfix[k]='\0';
   printf("postfix exp:");
   printf("%s",postfix);
   	
}
