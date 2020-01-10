#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* root=NULL;
void append()
{
	 struct node* temp;
	 temp=(struct node*)malloc(sizeof(struct node));
	 printf("Enter node data:");
	 scanf("%d",&temp->data);
	 temp->link=NULL;
	 if(root==NULL)
	 {
	 	root=temp;
	 }
	 else
	 {
	 	struct node* p=root;
	 	while(p->link!=NULL)
	 	{
	 		p=p->link;
		}
		p->link=temp;
	 }
}
void traverse()
{
	struct node* temp=root;
	if(root==NULL)
	{
		printf("No element in list:");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->link;
		}
	}
	printf("\n\n");
}
// it remove duplicate from unsorted list...
void remove_duplicate()
{
	struct node* p,*q,*r,*temp;
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
			q=q->link;
			r=r->link;
		}
		p=p->link;
		
	}
	
	

}

//it remove duplicate from sorted list...

void remove_duplicate_sorted()
{
	struct node* p,*q;
	p=root;
	while(p!=NULL&&p->link!=NULL)
	{
		if(p->data==p->link->data)
		{
			q=p->link->link;
			if(q==NULL)
			{
				p->link=NULL;
				break;
			}
			p->link=q;
		}
		if(p->data!=p->link->data)
		{
			p=p->link;
		}
	}
}
main()
{
	int ch;
	while(1)
	{
		printf(" 1.Insert at end\n 2.traverse\n 3.remove duplicate\n 4.remove_duplicate_sorted\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:append();
			       break;
			case 2:traverse();
			       break;
			case 3:remove_duplicate();
			       break;
			case 4:remove_duplicate_sorted();
			       break;
			default:printf("invalid input\n");		  
		}
	}
}
