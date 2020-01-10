#include<stdio.h>
#define CAPACITY 6
int stack1[CAPACITY];
int stack2[CAPACITY];
int top1=-1,top2=-1;
int temp,x;
void pop()
{
  int i;	
   
	 temp=stack1[top1];
	 top1--;
	

	
	
		    if(top2==-1)
        	{
	               top2++;
                   stack2[top2]=temp;
                  
	        }
        	else
        	{
			
			    if(temp>stack2[top2])
                	{
	        	     top2++;
		         	 stack2[top2]=temp;	
		         
		            }
		        else 
		        {
	                while(temp<stack2[top2])
	        	        {
	        		    x=stack2[top2];
	        			top1++;
						stack1[top1]=x;
						top2--;
				       
			            }
			          top2++;
	        	      stack2[top2]=temp;
	        	       
		    	}
		    }
    
     		
	 

	
	
}
void push(int x)
{
    int i;
	if(top1==CAPACITY-1)
	{
		printf("stack1 overflow:");
	}
	else
	{
		top1++;
		stack1[top1]=x;
	
	}

    printf("stack1-->top1:%d:\n",stack1[top1]);
	  
    
}
main()
{
	int i;
	push(3);
	push(23);
	push(31);
	push(34);
	push(92);
	push(98);
    while(top1!=-1)
      {
   	   pop();
      }
       printf("\n\nsorted stack\n\n");
      for(i=0;i<CAPACITY;i++)
      {
      	printf("stack2-->top%d:%d\n",i,stack2[i]);
	  }
	
}
