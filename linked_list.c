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
NODE insert_end(NODE first,int item)
{
	NODE new,last;
	new=getnode();
	new->value=item;
	new->next=NULL;
	if(first==NULL)
	{
		return new;
	}
	if(first==NULL)
	{
		first->next=new;
		return first;
	}
	last=first;
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=new;
	return first;
}
NODE insert_pos(NODE first,int item,int pos)
{
	int count=1;
	int val=item;
	NODE new,prev,curr;
	new=getnode();
	new->value=item;
	new->next=NULL;
	curr=first;
	if(first==NULL && pos==1)
	{
		return new;
	}
	while(count!=pos && curr!=NULL)
	{
		prev=curr;
		curr=curr->next;
		count++;
	}
	if(count==pos)
	{
		prev->next=new;
		new->next=curr;
		return first;
	}
	if(curr==NULL)
	{
		printf("Position not found\n");
		return first;
	}
	if(first!=NULL && pos==1)
	{
		first=insert_beg(first,val);
		return first;
	}
	
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
		printf("Value stored in the node=%d\n",temp->value);
		temp=temp->next;
	}
	
}
NODE del_beg(NODE first)
{
	NODE temp;
	if(first==NULL)
	{
		printf("list is empty\n");
		return first;
	}
	temp=first;
	temp=temp->next;
	printf("Item deleted =%d",first->value);
	free(first);
	return temp;
	
}
NODE del_end(NODE first)
{
	NODE curr,prev;
	if(first==NULL)
	{
		printf("list is empty\n");
		return first;
	}
	prev=NULL;
	curr=first;
	while(curr->next!=NULL)
	{
		prev=curr;
		curr=curr->next;
	}
	prev->next=NULL;
	printf("%d",curr->value);
	free(curr);
	return first;
}
NODE del_value(NODE first,int key)
{
	NODE prev,curr;
	if(first==NULL)
	{
		printf("list is empty\n");
		return first;
	}
	curr=first;
	if(curr->value==key)
	{
		printf("Item deleted =%d",curr->value);
		first=first->next;
		free(curr);
		return first;
	}
	prev=NULL;
	curr=first;
	while(curr->value!=key && curr!=NULL)
	{
		prev=curr;
		curr=curr->next;
	}
	if(curr->value==key)
	{
		prev->next=curr->next;
		printf("Item deleted %d=",curr->value);
		free(curr);
		return first;
	}
	if(curr==NULL)
	{
		printf("End of list reached and item not found\n");
		return first;
	}
	
}
int main()
{
	int pos,item,c;
	NODE first=NULL;
	while(1)
	{
		printf("\n1.Insert at beginning\n2.Insert at the end\n3.Insert at any given position\n4.Display\n5.Delete at beginning\n6.Delete at the end\n7.Delete a specific element\n");
		printf("Enter your choice :");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("Enter the item to be inserted :");
					scanf("%d",&item);
					first=insert_beg(first,item);
					break;
			case 2:printf("Enter the item to be inserted :");
					scanf("%d",&item);
					first=insert_end(first,item);
					break;
			case 3:printf("Enter the item to be inserted :");
					scanf("%d",&item);
					printf("Enter the position :");
					scanf("%d",&pos);
					first=insert_pos(first,item,pos);
					break;
			case 4:display(first);
					break;
			case 5:del_beg(first);
					break;
			case 6:del_end(first);
					break;
			case 7:del_value(first);
					break;
			default:printf("Invalid choice!!!");
					exit(0);
		}
	}
}
