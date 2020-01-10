//level order traversasl......
#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 10
int front=0;
int rear=0;
struct BSTnode
{
	int data;
	struct BSTnode* left;
	struct BSTnode* right;
};
struct BSTnode* root=NULL;
struct BSTnode* queue[CAPACITY];
void insert()
{
	struct BSTnode* temp,*parent;
	temp=(struct BSTnode*)malloc(sizeof(struct BSTnode));
	printf("Enter node data:");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	parent=root;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct BSTnode* curr;
		curr=root;
		while(curr)
		{
			parent=curr;
			if(temp->data>curr->data)
			{
				curr=curr->right;
			}
			else
			{
				curr=curr->left;
			}
			
        }
		if(temp->data>parent->data)
		{
			parent->right=temp;
		}
		else
		{
			parent->left=temp;
		}
		
	}
	printf("\n");	 
}
void dqueue()
{
	int i;
	for(i=0;i<rear;i++)
	{
		queue[i]=queue[i+1];
	}
	rear--;
}

void Enqueue(struct BSTnode* root)
{
	struct BSTnode* temp=root;
	if(rear==CAPACITY)
	{
		printf("queue is full");
	}
	queue[rear]=root;
	rear++;
	while(rear!=front)
	{	
	   temp=queue[front];
	   printf("%d ",temp->data);
	   if(temp->left!=NULL)
	   {
	   	  
	   	   queue[rear]=temp->left;
	   	    rear++;
	   }
	   if(temp->right!=NULL)
	   {   
	       
	   	   queue[rear]=temp->right;
	   	   rear++;
	   }
	   dqueue();
	}
}

main()
{
	int ch;
	while(1)
	{
		printf(" 1.Insert\n 2.Level Order Traversal Print In One Line\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert();
			        break;
			case 2:Enqueue(root);
			        break;
			default:printf("invalid choice:");
		}
	}
}
