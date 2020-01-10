//single link list...append a node in end of link list..
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* root=NULL;
int len;
void addAtend()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter node data:");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node* p;
		  p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		    p->link=temp;
		    
	}
}
int length()
{
	int count=0;
	struct node* temp;
	temp=root;
	while(temp!=NULL)
      {
      	count++;
      	temp=temp->link;
	  }	
	  return count;
}
void  addAtbegin()
{
	struct node* temp; 
   temp=(struct node*)malloc(sizeof(struct node));
   printf("enter the node:");
   scanf("%d",&temp->data);
   temp->link=NULL;
   if(root==NULL)
   {
   	    root=temp;
   }
   else
   {
   	 temp->link=root;
   	 root=temp;
   }
   
}
void addAtafter()
{
	struct node* temp,*p;
	int loc,len,i=1;
	printf("Enter location where You want to add node:");
	scanf("%d",&loc);
	len=length();
	if(loc>len)
	{
		printf("Invalid location:\n");
		printf("currentlt list haveing:%d node\n:-",len);
	}
	else
	{
	    p=root;
	    while(i<loc)
	    {
	    	p=p->link;
	    	i++;
		}
	 temp=(struct node*)malloc(sizeof(struct node));
	 printf("Enter node data:");
	 scanf("%d",&temp->data);
	 temp->link=NULL;
	 temp->link=p->link;
	 p->link=temp;
	 	 
   }
    
	 
	 
	
}
void display()
{
	struct node* temp;
	temp=root;
    if(temp==NULL)
    {
    	printf("\n***No element in Link list***:\n\n");
	}
	else
	{
		while(temp!=NULL)
		{
		  printf("%d-->",temp->data);
		  temp=temp->link;	
		}
		printf("\n");
	}
}
void Delete()
{
   struct node* temp;
   int loc;
   printf("Enter location:");
   scanf("%d",&loc);
   if(loc>length())
   {
   	 printf("Invalid location:\n");
   	 printf("currently list having %d nodes\n",length());
   }
   else if(loc==1)
   {
   	  temp=root;
   	  root=temp->link;
   	  temp->link=NULL;
   	  free(temp);
   	  
   }
   else
   {
   	 struct node* p,*q;
   	 int i=1;
   	 p=root;
   	 while(i<loc-1)
   	 {
   	 	p=p->link;
   	 	i++;
   	 	
	 }
	 q=p->link;
	 p->link=q->link;
	 q->link=NULL;
	 free(q);
   	
   }	
}
void swapNode()
{
	struct node* p,*q,*r;
	int i=1,loc;
	printf("Enter Location:");
	scanf("%d",&loc);
    if(loc>length())
	{
		 printf("Invalid location:\n");
   	     printf("currently list having %d nodes\n",length());
	}
	else
		{
	       p=root;
           while(i<loc-1)
            {
   	          p=p->link;
   	          i++;
            }
           q=p->link;
           r=q->link;
           q->link=r->link;
           r->link=q;
           p->link=r;
         }
}
void reverse_list()
{
	int i,j,k,len,temp;
	struct node* p,*q;
	len=length();
	i=0;j=len-1;
	p=root;
	q=root;
	while(i<j)
	{
		k=0;
		while(k<j)
		{
			 q=q->link;
			 k++;
		}
		temp=p->data;
		p->data=q->data;
		q->data=temp;
		i++;
		j--;
		p=p->link;
		q=root;		 
		
	}


}
//remove duplicate from unsorted list.........
void remove_diplicate()
{
	struct node* p,*q,*temp,*r;
	if(root==NULL)
	{
		printf("list is empty");
	}
	else
	{
		   p=root; 
		   while(p->link!=NULL)
		   {
		   	    q=p->link;
		   	    r=p;
		   	     while(q!=NULL)
		   	     {
		   	     	   
		   	     	   if(p->data==q->data)
		   	     	   {
		   	     	   	  temp=q;
		   	     	   	  
		   	     	   	  r->link=temp->link;
		   	     	   	  temp->link=NULL;
		   	     	   	  free(temp);
		   	     	   	  q=r->link;
					   }
					   else
					   {
					   	   q=q->link;
					   	   r=r->link;
					   }
		   	     	 
		   	     	 	
				 } 
				 p=p->link;
	       }
		
	}
}
main()
{
	int ch;

		while(1)

        {
        	printf(" 1.addAtbegin\n 2.addAtend\n 3.addAtafter\n 4.length\n 5.display\n 6.delete\n 7.swapNode\n 8.reverse_list\n 9.removeDuplicate\n 10.exit\n");
        	printf(" Enter your choice:-");
	        scanf("%d",&ch);
        	 switch(ch)
            	{
        	
 		           case 1:  addAtbegin();
		                    break;
		           case 2:  addAtend();
		                    break;
		           case 3:  addAtafter();
		                    break;
		           case 4:  len=length();
		                    printf("Length:%d\n",len);
		                    break;
	               case 5:  display();
		                    break;
		           case 6:  Delete();
		                    break;
		           case 7:  swapNode();
		                    break;
		           case 8:  reverse_list();
		                    break;
		           case 9:  remove_diplicate();
		                    break;
		           case 10: exit(0);
		           default: printf("Invalid choice\n\n:");
		           
		           
              }
	   	       	
    	}
	
}
