#include<stdio.h>
#include<string.h>
# define CAPACITY 50
char stack[CAPACITY];
int top=-1;
void push(char ch)
{
	if(top==CAPACITY-1)
	{
		printf("overflow:");
	}
	else
	{
		top++;
		stack[top]=ch;
	}
}
void pop()
{
	top--;
}
int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	return 0;
}
char peek()
{
	return stack[top];
}
int ArePair(char opening,char closing)
{
	if(opening=='(' && closing==')')
	{
		return 1;
	}
	else if(opening=='{'&& closing=='}')
	{
		return 1;
	}
	else if(opening=='['&& closing==']')
	{
		return 1;
	}
	return 0;
}
int AreParenthesisBalanced(char exp[])
{
	int i;
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(' || exp[i]=='{' ||exp[i]=='[')
		{
			push(exp[i]);
		}
	    else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
	    {
	    	if(isEmpty()||!ArePair(peek(),exp[i]))
	    	{
	    		return 0;
			}
			else
			   pop();
		}
		
	}
	return isEmpty()?1:0;
}
main()
{
	char s[50];
	printf("enter the expression:");
	scanf("%s",s);
	if(AreParenthesisBalanced(s))
	 printf("Balanced:");
	else
	 printf("Not Balanced:");
}
