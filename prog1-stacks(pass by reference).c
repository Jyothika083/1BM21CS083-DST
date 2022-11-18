

#include <stdio.h>
#include<stdlib.h>
#define STACK_SIZE 5
void push(int st[],int *top)
{
	int item;
 	if(*top==STACK_SIZE-1)
		printf("Stack overflow\n");
	else
	{
		printf("\nEnter an item :");
		scanf("%d",&item);
		(*top)++;
		st[*top]=item;
	}
}
int pop(int st[],int *top)
{
	int del_item;
	if(*top==-1)
		printf("Stack underflow\n");
	else
	{
		del_item=st[*top];
		(*top)--;
		return del_item;
	}
}
void display(int st[],int *top)
{
	int i;
	if(*top==-1)
		printf("Stack is empty\n");
	else
	{
	for(i=0;i<=*top;i++)
		printf("%d\t",st[i]);
	}
}
void main()
{
	int st[10],top=-1, c,val_del;
	while(1)
	{
		printf("\n1. Push\n2. Pop\n3. Display\n");
		printf("\nEnter your choice :");
		scanf("%d",&c);
		switch(c)
		{
			case 1: push(st,&top);
					break;
			case 2: val_del=pop(st,&top);
					printf("\n%d item was deleted",val_del);
					break;
			case 3: display(st,&top);
					break;
			default: printf("\nInvalid choice!!!");
					 exit(0);
					 break;
		}
	}
}

		

		

		


		
