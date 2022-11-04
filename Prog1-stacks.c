#include <stdio.h>
#include<stdlib.h>
#define STACK_SIZE 5
int st[10],item,top=-1;
void push()
{
 	if(top==STACK_SIZE-1)
		printf("Stack overflow\n");
	else
	{
		top++;
		st[top]=item;
	}
}
int pop()
{
	int del_item;
	if(top==-1)
		printf("Stack underflow\n");
	else
	{
		del_item=st[top];
		top--;
		return del_item;
	}
}
void display()
{
	int i;
	if(top==-1);
		printf("Stack is empty\n");
		for(i=0;i<=top;i++)
			printf("%d\t",st[i]);
}
void main()
{
	int c;
	while(1)
	{
		printf("\n1. Push\n2. Pop\n3. Display\n");
		printf("\nEnter your choice :");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("\nEnter an item :");
					scanf("%d",&item);
					push();
					break;
			case 2: printf("\n%d item was deleted",pop());
					break;
			case 3: display();
					break;
			default: printf("\nInvalid choice!!!");
					 exit(0);
					 break;
		}
	}
}

		

		

