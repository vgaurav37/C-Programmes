//stack using link list...... 
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* top=NULL;
void push()
{
   struct node* temp;
   temp= (struct node*)malloc(sizeof(struct node));
   printf("Enter node data:");
   scanf("%d",&temp->data);
   temp->link=top;
   top=temp;
}
void pop()
{
	struct node* temp;
	if(top==NULL)
	{
		printf("no element for deletion:\n");
	}
	else
	{
		temp=top;
		printf("element %d\n",temp->data);
		top=top->link;
		temp->link=NULL;
		free(temp);
	}
}
void traverse()
{
	struct node* temp;
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		temp=top;
		while(temp!=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->link;
				
		}
		printf("\n");
	}
}
main()
{
	int ch;
	while(1)
	{
		printf(" 1.push\n 2.pop\n 3.traverse\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
			      break;
			case 2:pop();
			      break;
			case 3:traverse();
			      break;
			defualt:printf("invalid choice:");
			      
		}
	}

}
