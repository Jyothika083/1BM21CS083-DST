#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Memory not allocated\n");
        return NULL;
    }
    return temp;
}
NODE insert_beg(NODE first, int item)
{
    NODE new;
    new=getnode();
    new->value=item;
    new->next=NULL;
    new->prev=NULL;
    if(first==NULL)
        return new;
    new->next=first;
    first->prev=new;
    return new;
}
NODE insert_left(NODE first,int item,int key)
{
    NODE new,temp;
    new=getnode();
    new->value=item;
    new->next=NULL;
    new->prev=NULL;
    if(first==NULL)
    {
        printf("list is empty there no left element\n");
        return first;
    }
    if(first->next==NULL && first->value==key)
    {
        new->next=first;
        first->prev=new;
        return new;
    }
    if(first->next==NULL && first->value!=key)
    {
        printf("value not found cannot be inserted to left\n");
        return first;
    }
    if(first->value==key)
    {
        first=insert_beg(first,item);
        return first;
    }
    temp=first;
    while(temp->value!=key && temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->value==key)
    {
        new->next=temp;
        new->prev=temp->prev;
        temp->prev->next=new;
        temp->prev=new;
        return first;
    }
    if(temp->value!=key)
    {
        printf("value not found cannot insert to left\n");
        return first;
    }

}
NODE delete_specific(NODE first,int key)
{
    NODE curr,temp;
    if(first==NULL)
    {
        printf("list is empty\n");
        return first;
    }
    if(first->next==NULL && first->value!=key)
    {
         printf("value not found\n");
         return first;
    }
    if(first->next==NULL && first->value==key)
    {
        free(first);
        return first;
    }
    if(first->value==key)
    {
        first->next->prev=NULL;
        temp=first->next;
        free(first);
        return temp;
    }
    curr=first;
    while(curr->value!=key && curr!=NULL)
    {
        curr=curr->next;
        if(curr==NULL)
        {
            printf("element not found cannot delete\n");
            return first;
        }

    }
    if(curr->value==key)
    {
        curr->prev->next=curr->next;
        if(curr->next!=NULL)
        {
            curr->next->prev=curr->prev;
        }
        free(curr);
        return first;
    }
}
void display(NODE first)
{
    NODE temp;
    temp=first;
    if(temp==NULL)
    {
        printf("list is empty");
    }
    while(temp!=NULL)
    {
        printf("%d\t",temp->value);
        temp=temp->next;
    }
}
void main()
{
	int c,item,key;
    NODE first=NULL;
	while(1)
	{
		printf("\n1. Insert at the beginning \n2.Insert to the left of a node\n3.Delete a specific element\n4.Display\n");
		printf("\nEnter your choice :");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("\nEnter item to be inserted :");
					scanf("%d",&item);
					first=insert_beg(first,item);
					break;
			case 2: printf("\nEnter item to be inserted :");
					scanf("%d",&item);
                    printf("\nEnter key element :");
					scanf("%d",&key);
                    first=insert_left(first,item,key);
					break;
			case 3: printf("\nEnter item to be deleted :");
					scanf("%d",&key);
                    first=delete_specific(first,key);
                    break;
            case 4: display(first);
					break;
			default: printf("\nInvalid choice!!!");
					 exit(0);
					 break;
		}
	}
}

