#include<stdio.h>
#include<stdlib.h>
#define QSIZE 3
void insert_rear(int q[],int item, int*r)
{
	if(*r==QSIZE-1)
		printf("Queue Overflow\n");
	else
	{
		(*r)++;
		q[*r]=item;
	}
		
}
int delete_front(int q[],int *r,int *f)
{
	if(*f>*r)
		printf("Queue underflow\n");
	else
		return q[(*f)++];
}
void display(int q[],int *r,int *f)
{
	int i;
	if(*f>*r)
		printf("Queue is empty\n");
	else
	{
		for(i=*f;i<=*r;i++)
			printf("%d\t",q[i]);
	}
}
void main()
{
	int q[QSIZE],r=-1, f=0,	c,val_del,item;
	while(1)
	{
		printf("\n1. Insert\n2. Delete\n3. Display\n");
		printf("\nEnter your choice :");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter item to be inserted :");
					scanf("%d",&item);
					insert_rear(q,item,&r);
					break;
			case 2: val_del=delete_front(q,&r,&f);
					printf("\n%d was deleted\n",val_del);
					break;
			case 3: display(q,&r,&f);
					break;
			default: printf("\nInvalid choice!!!");
					 exit(0);
					 break;
		}
	}
}
