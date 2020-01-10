#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 10
int front=0;
int rear=0;
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root=NULL;
struct node* queue[CAPACITY];
void insert()
{
	struct node* t,*parent,*curr;
	t=(struct node*)malloc(sizeof(struct node));
	printf("enter node data:");
	scanf("%d",&t->data);
	t->left=NULL;
	t->right=NULL;
	if(root==NULL)
	{
		root=t;
	}
	else
	{
		parent=root;
		curr=root;
		while(curr)
		{
			parent=curr;
			if(t->data>curr->data)
			{
				curr=curr->right;
			}
			else
			{
				curr=curr->left;
			}
		}
		if(t->data>parent->data)
		{
			parent->right=t;
		}
		else
		{
			parent->left=t;
		}
	}
	
}
struct node* find_min(struct node* root)
{
	struct node* temp;
	temp=root;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}

struct node* delete_bst(struct node* root,int data)
{
	  struct node* temp;
	  if(root==NULL)
	  {
	  	printf("tree is empty:");
	  }
	  else if(data<root->data)
	  {
	  	   root->left=delete_bst(root->left,data);
	  }
	  else if(data>root->data)
	  {
	  	 root->right=delete_bst(root->right,data);
	  }
	  else
	  {
	  	  //case 1 no chiled
	  	  if(root->left==NULL&& root->right==NULL)
	  	  {
	  	  	   free(root);
	  	  	   root=NULL;
		  }
		  //case 2 having one child.
		  
		  else if(root->left==NULL)
		  {
		  	  struct node* temp=root;
		  	  root=root->right;
		  	  free(temp);
		  }
		  else if(root->right==NULL)
		  {
		  	  struct node* temp=root;
		  	  root=root->left;
		  	  free(temp);
		  }
		  
		  //case 3 having two child;
		  else
		  {
		  	struct node*temp=find_min(root->right);
		  	root->data=temp->data;
		  	root->right=delete_bst(root->right,temp->data);
		  }
	  }
	  return root;
}
void inorder(struct node* root)
{
	struct node* temp;
	if(root==NULL)
	{
		return;
	}
	else
	{
		temp=root;
		inorder(temp->left);
		printf("%d-->",temp->data);
		inorder(temp->right);
	}
}
void preorder(struct node* root)
{
	struct node* temp;
	if(root==NULL)
	{
		return;
	}
	else
	{
		temp=root;
		printf("%d-->",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void postorder(struct node* root)
{
	struct node* temp;
	if(root==NULL)
	{
		return;
	}
	else
	{
		temp=root;
		preorder(temp->left);
		preorder(temp->right);
		printf("%d-->",temp->data);
	}
}
int height(struct node* root)
{
	struct node* temp;
	int h,left,right;
	temp=root;
	if(root==NULL)
	{
		return 0;
	}
	else
	{
	  left=height(temp->left);
	  right=height(temp->right);
	}
	if(left>right)
	{
		h=left+1;
	}
	else
	{
		h=right+1;
	}
	return h;
}
struct node* search(struct node* root,int key)
{
	struct node* temp;
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==key)
	{
		return root;
	}
	else if(key>root->data)
	{
		return search(root->right,key);
	}
	else if(key<root->data)
	{
	   return search(root->left,key);
	}
	
}
int is_SubtreeLesser(struct node* root,int value)
{
      if(root==NULL)
      {
      	 return 1;
	  }
	 
	  if(root->data<value&&is_SubtreeLesser(root->left,value)&&is_SubtreeLesser(root->right,value))
	  {
	  	 return 1;
	  }
	  else
	  {
	  	 return 0;	
	  } 
	   
}
int is_SubtreeGreater(struct node* root,int value)
{
	if(root==NULL)
	return 1;
	if(root->data>value&&is_SubtreeGreater(root->left,value)&&is_SubtreeGreater(root->right,value))
	{
		return 1;
	}
	else
	   return 0;	 
}
int is_Bst(struct node* root)
{
	 if(root==NULL)
	 {
	 	return 1;
	 }
	 
	 if(is_SubtreeLesser(root->left,root->data)&&is_SubtreeGreater(root->right,root->data)&&is_Bst(root->left)&&is_Bst(root->right))
	 {
	 	return 1;
	 }
	 else
	 {
	 	return 0;
	 }
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
void Enqueue(struct node* root)
{
	struct node* temp;
	if(rear==CAPACITY)
	{
		printf("queue is empty:");
	}
	else
	{
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
}










main()
{
	int ch,target,hit,key,check;
	struct node* min,*found;
	while(1)
	{
		printf(" 1.insert in BST\n 2.inorder\n 3.preorder\n 4.postorder\n 5.find min\n 6. delete in Bst\n 7.height\n 8.search\n 9.isBst\n 10.level Order Traversal\n");
		printf("Enter your choice:-");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();
			      break; 
			case 2:inorder(root);printf("\n");
			      break;
			case 3:preorder(root);printf("\n");
			      break;
			case 4:postorder(root);printf("\n");
			      break; 
			case 5:min=find_min(root);
			       printf("\n%d",min->data);
			       break;
			case 6:
			    printf("enter node:");
			    scanf("%d",&target);
			    delete_bst(root,target); 
				break; 
			case 7:hit=height(root) ;
			       printf("%d",hit);
			       break;
			case 8:printf("Enter key:");
			       scanf("%d",&key);
			       found=search(root,key);
			       if(found==NULL)
			       {
			       	printf("not found");
				   }
				   else
				   {
				   	printf("found");
				   }
			       break;
			case 9:check=is_Bst(root);
			       if(check==1) 
				    {
				    	printf("Yes it is Bst\n");
					}
					else
					{
						printf("NO it is not Bst\n");
					}
			       break;
			case 10:Enqueue(root);
				    break;
			default:printf("invalid choice:\n");
		}
	}
}
