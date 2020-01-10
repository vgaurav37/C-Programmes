#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root=NULL;
void append()
{
	struct node* temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data:");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		p=root;
		while(p->right!=NULL)
		{
			p=p->right;
		}
		p->right=temp;
		temp->left=p;
	}
}
void addatbegin()
{ 
    struct node* temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data:");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp->right=root;
		root->left=temp;
		root=temp;
	}
	
}
int length()
{
	struct node* temp=root;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->right;
	}
	return count;
}
void addatafter()
{
	struct node* temp,*p;
	int len,loc,i=1;
	printf("enter location:");
	scanf("%d",&loc);
	len=length();
	if(loc>len)
	{
		printf("invalid location:");
	}
	else
	{
		temp=(struct node*)malloc(sizeof(struct node));
	    printf("Enter node data:");
	    scanf("%d",&temp->data);
	    temp->left=NULL;
	    temp->right=NULL;
	    p=root;
	    while(i<loc)
	    {
	    	p=p->right;
	    	i++;
		}
		temp->right=p->right;
		p->right->left=temp;
		temp->left=p;
		p->right=temp;
	}
}
void reverse_doubly()
{
	struct node* curr=root,*temp;
	if(curr==NULL)
	{
		
	}
	if(curr->right==NULL)
	{
		
	}

	while(curr!=NULL)
	{
		temp=curr->left;
		curr->left=curr->right;
		curr->right=temp;
		curr=curr->left;
	}
	if(temp!=NULL)
	 temp=temp->left;
}
void traverse()
{
	struct node* temp;
	if(root==NULL)
	{
		printf("list is empty:");
	}
	else
	{
		temp=root;
		while(temp!=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->right;
		}
	}
	printf("\n");
}
main()
{
	int ch;
	while(1)
	{
		printf(" 1.Append\n 2.Add at beging \n 3.Add at after\n 4.traverse\n 5.reverse doubly\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:append();
			       break;
			case 2:addatbegin();
			       break;
			case 3:addatafter();
			       break;
			case 4:traverse();
			       break;
			case 5:reverse_doubly();
			       break;
			default:printf("invalid choice:!try again");
			       
		}
	}
}
