#include<stdio.h>
#include<stdlib.h>
int count;
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
        count++;
		return new;
	}
	else
	{
		new->next=first;
		first=new;
        count++;
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
NODE sort(NODE first)
{
    NODE curr=first;
    int temp,i,j;
    if(first->next==NULL)
        return first;
    for(i=0;i<count-1;i++)
    {
        curr=first;
        for(j=0;j<count-i-1;j++)
        {
            if(curr->value>curr->next->value)
            {
                temp=curr->value;
                curr->value=curr->next->value;
                curr->next->value=temp;
            }
            curr=curr->next;
        }
    }
    return first;
    
}
int main()
{
	int item,c;
	NODE first=NULL;
	while(1)
	{
		printf("\n1.Insert at beginning\n2.Sort\n3.Display\n");
		printf("Enter your choice :");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("Enter the item to be inserted :");
					scanf("%d",&item);
					first=insert_beg(first,item);
					break;
			case 2:first=sort(first);
                    break;
            case 3:display(first);
                    break;
			default:printf("Invalid choice!!!");
					exit(0);
		}
	}
}