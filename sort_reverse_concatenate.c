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
int countfun(NODE first)
{
    NODE temp=first;int c=0;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
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
    int count=countfun(first);
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
NODE reverse(NODE first)
{
    NODE prev=NULL;
    NODE curr=first;
    NODE next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

    }
    first=prev;
    return prev;
}
	

int main()
{
	int item,c;
	int count1=0,count2=0;
	NODE first1=NULL,first2=NULL;
	while(1)
	{
		printf("\n1.Insert at beginning for list1\n2.Insert at beginning for list2\n3.Sort list1\n3.Sort list2\n5.Concatenate(output is stored in list1)\n6.Reverse list1\n7.Reverse list2\n8.Display list1\n9.Display list2\n\n");
		printf("Enter your choice :");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("Enter the item to be inserted :");
				scanf("%d",&item);
				first1=insert_beg(first1,item);
				break;
			case 2:printf("Enter the item to be inserted :");
				scanf("%d",&item);
				first2=insert_beg(first2,item);
				break;
			case 3:first1=sort(first1);
                    		break;
			case 4:first2=sort(first2);
                    		break;
			case 5:first1=concatenate(first1,first2);
                    		break;
			case 6:first1=reverse(first1);
                    		break;	
			case 7:first2=reverse(first2);
                    		break;	
            case 8:display(first1);
                    		break;
			case 9:display(first2);
                    		break;	
			default:printf("Invalid choice!!!");
					exit(0);
		}
	}
}