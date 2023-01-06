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
NODE sort(NODE first,int count)
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
NODE concatenate(NODE first1, NODE first2)
{
	NODE temp;
	temp=first1;
	if(first1==NULL && first2==NULL)
	{
		return NULL;
	}
	if(first1==NULL)
	{
		return first2;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=first2;
	return first1;
}
	

int main()
{
	int item,c;
	int count1=0,count2=0;
	NODE first1=NULL,first2=NULL,first3=NULL;
	while(1)
	{
		printf("\n1.Insert at beginning or list1\n2.Insert at beginning or list2\n3.Sort list1\n\n3.Sort list2\n5.Concatenate\n6.Display\n");
		printf("Enter your choice :");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("Enter the item to be inserted :");
				scanf("%d",&item);
				first1=insert_beg(first1,item);
				count1++;
				break;
			case 1:printf("Enter the item to be inserted :");
				scanf("%d",&item);
				first2=insert_beg(first2,item);
				count2++;
				break;
			case 2:first1=sort(first1,count1);
                    		break;
			case 2:first2=sort(first2,count2);
                    		break;
			case 2:first3=sort(first2,count2);
                    		break;
            		case 3:display(first);
                    		break;
			default:printf("Invalid choice!!!");
					exit(0);
		}
	}
}
