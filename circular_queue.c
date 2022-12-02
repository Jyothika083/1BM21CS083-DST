#include<stdio.h>
#include<stdlib.h>
#define QSIZE 3
int count=0;
void insert_rear(int q[],int item, int*r)
{
	if(count==QSIZE)
		printf("Queue Overflow\n");
	else
	{
		(*r)=(*r)+1;
		(*r)=(*r)%QSIZE;
		q[*r]=item;
		count++;
	}
		
}
int delete_front(int q[],int *r,int *f)
{
	int del_item;
	if(count==0)
		printf("Queue underflow\n");
	else
	{
		del_item=q[*f];
		(*f)=(*f)+1;
		(*f)=(*f)%QSIZE;
		count--;
	
		return del_item;
	}
		
}
void display(int q[],int *f)
{
	int temp,i;
	temp=(*f);
	if(count==0)
		printf("Queue is empty\n");
	
	{
	
		for(i=0;i<count;i++)
		{
			printf("%d\t",q[temp]);
			temp=(temp+1)%QSIZE;
		}
			
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
			case 3: display(q,&f);
					break;
			default: printf("\nInvalid choice!!!");
					 exit(0);
					 break;
		}
	}
}
