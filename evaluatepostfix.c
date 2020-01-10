#include<stdio.h>
#define CAPACITY 50
int stack[CAPACITY];
int top=-1;
void push(int x)
{
	if(top==CAPACITY-1)
	{
		printf("stack is empty:");
	}
	else
	{
		top++;
		stack[top]=x;
	}
}
int pop()
{
	int x=stack[top];
	top--;
	return x;
}
int is_operand(char item)
{
	if(item>='A'&& item<='Z'||item>='a'&&item<='z')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
main()
{
	char postfix[50],item;
	int i=0,op1,op2,result,m;
	printf("Enter postfix expression:");
	scanf("%s",postfix);
	while(postfix[i]!='\0')
	{
		item=postfix[i];
		if(is_operand(item)==1)
		  {
			printf("Enter value of %c:",item);
			scanf("%d",&m);
			push(m);
		  }
		else
		{
		    op2=pop();
			op1=pop();
			switch(item)
			{
				case '+':result=op1+op2;
				        push(result);
			           	break;
			    case '-':result=op1-op2;
			            push(result);
			           	break;
			    case '*':result=op1*op2;
			            push(result);
			           	break;
			    case '/':result=op1/op2;
			            push(result);
			           	break;
			    case '^':result=op1^op2;
			            push(result);
			           	break;
			    default:printf("invalid opearater:");
			}
		}
		i++;
		
	}
	result=pop();
	printf("%d",result);
}
