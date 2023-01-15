#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Memory not allocated");
		return NULL;
	}
	return temp;
}
NODE insert_beg(NODE first,int item)
{
	NODE new;
	new=getnode();
	new->value=item;
	new->next=NULL;
	if(first==NULL)
	{
		return new;
	}
	else
	{
		new->next=first;
		first=new;
		return first;
	}
}
NODE delete_duplicate(NODE first)
{
    NODE i,j,temp;
    i=first;
    j=first->next;
    if(first==NULL || first->next==NULL)
        return first;
    while(i->next!=NULL)
    {
        if(i->value==j->value)
        {
            temp=j;
            i->next=j->next;
            j=j->next;
            free(temp);
        }
        else
        {
            i=i->next;
            j=j->next;
        }
    }
    return first;
}
void display(NODE first)
{
	NODE temp;
	temp=first;
	if(first==NULL)
	{
		printf("List is empty\n");
	}
	while(temp!=NULL)
	{
		printf("%d\t",temp->value);
		temp=temp->next;
	}
	
}
void main()
{
	int c,item;
    NODE first=NULL;
	while(1)
	{
		printf("\n1. Insert\n2. delete duplicate\n3. Display\n");
		printf("\nEnter your choice :");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("\nEnter an item :");
					scanf("%d",&item);
					first=insert_beg(first,item);
					break;
			case 2: first=delete_duplicate(first);
					break;
			case 3: display(first);
					break;
			default: printf("\nInvalid choice!!!");
					 exit(0);
					 break;
		}
	}
}
