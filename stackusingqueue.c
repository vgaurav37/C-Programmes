//stack using queue
#include<stdio.h>
#define CAPACITY 5	
int queue1[CAPACITY];
int queue2[CAPACITY];
int front1=0;
int rear1=0;
int front2=0;
int rear2=0;
void push()
{
   if(rear1==CAPACITY)
   {
   	  printf("stack is full");
   }
   else
   {
   	   int ele;
   	   printf("Enter element:");
   	   scanf("%d",&ele);
   	   queue1[rear1]=ele;
   	   printf("pushed:%d\n",queue1[rear1]);
   	   rear1++;
   }
   
}
void pop()
{
	    int flag=1;
	    if(flag)
	    {
	    	
	    	    if(CAPACITY==rear2)
		        {
		        	printf("queue2 is full");
				}
				else
				{
					int i=0;
					while(i<rear1-1)
		             {
			           queue2[i]=queue1[i];
			           i++;
			           
	     	         }
	     	     int ele=queue1[i];
	        	 rear1--;
	        	 printf("element deleted %d\n",ele);
	        	}
	        	 
	        	flag=0;
	        	
	    }	
		
		else
	    {
	            if(CAPACITY==rear1)
				{
					printf("queue1 is full");
			    } 
				else
				{
				   int i=0;
				   while(i<rear2-1)	
				   {
				   	       queue1[i]=queue2[i];
				   	       i++;
				   	       
				   }
				   int ele1=queue2[i];
				   printf("element deleted %d",ele1);
				   rear2--;
				   	
				} 
			flag=1;	
		}
		
	
}
void traverse()
{
	int i=0,flag=1;
	if(flag)
	{
		for(i=0;i<rear1;i++)
        	{
		      printf("%d\t",queue1[i]);
	        }
			printf("\n");
		
	}

	else
	{
		       for(i=0;i<=rear2;i++)
        	   {
		          printf("%d\t",queue2[i]);
	           }
			printf("\n");
			flag=1;
		
	}
	
}
main()
{
	int ch;
	while(1)
	{
		printf(" 1.push\n 2.pop\n 3.traverse\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
			       break;
			case 2:pop();
			       break;
			case 3:traverse();
			       break;
			default:printf("invalid choice");
		}
	}
}
