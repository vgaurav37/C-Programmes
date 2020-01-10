#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* root=NULL;
struct node* detectloop()
{
	struct node*p,*q;
	p=q=root;
	while(p&&q && q->link)
	{
		p=p->link;
		q=q->link->link;
	
		if(p==q)
		{
		
			printf("LOOP FOUND:\n");
			return p;
		}	
		
	}
	
	 	 return NULL;
	 
	 
	
}
void start_loop(struct node* p)
{
	struct node* q;
	q=root;
	while(p!=q)
	{
		p=p->link;
		q=q->link;
	}
	printf("LOOP START FROM THIS NODE:%d \n",p->data);
}

void remove_loop(struct node* p)
{
	struct node* q,*r,*s;
	q=root;
    s=root;
	while(p!=q)
	{
		r=p;
		p=p->link;
		q=q->link;
		
	}
	r->link=NULL;
	
	printf("\nAfter removing loop the list is:\n");
	while(s!=NULL)
	{
		printf("%d-->",s->data);
		s=s->link;
		
	}
	
}
/*
void display(struct node* root)
{
	struct node* temp;
	temp=root;
    printf("list is\n");


	 
		while(temp!=NULL)
		{
		  printf("%d-->",temp->data);
		  temp=temp->link;	
		}
     
}

*/
main()
{
	struct node* one,*two,*three,*four,*five,*six;
	one=(struct node*)malloc(sizeof(struct node));
	two=(struct node*)malloc(sizeof(struct node));
	three=(struct node*)malloc(sizeof(struct node));
	four=(struct node*)malloc(sizeof(struct node));
	five=(struct node*)malloc(sizeof(struct node));
	six=(struct node*)malloc(sizeof(struct node));
    root=one;
    one->data=1;
    one->link=two;
    two->data=2;
    two->link=three;
    three->data=3;
    three->link=four;
    four->data=4;
    four->link=five;
    five->data=5;
    five->link=six;
    six->data=6;
    six->link=three;
    struct node* temp;
	temp=detectloop();
	if(temp==NULL)
	{
		printf("NOT FOUND:\n");
	}
	else
	{
		start_loop(temp);
		remove_loop(temp);
	}
	
   	
}
	
	
	

