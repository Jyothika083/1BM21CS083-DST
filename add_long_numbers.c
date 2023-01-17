#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory not allocated");
        return NULL;
    }
    return temp;
}
NODE insert_beg(NODE first, int item)
{
    NODE new;
    new = getnode();
    new->value = item;
    new->next = NULL;
    if (first == NULL)
    {
        return new;
    }
    else
    {
        new->next = first;
        first = new;
        return first;
    }
}
void display(NODE first)
{
	NODE temp;
	temp=first;
	if(first==NULL)
	{
		printf("\nList is empty\n");
	}
	while(temp!=NULL)
	{
		printf("\t%d",temp->value);
        
		temp=temp->next;
	}
	printf("\n");
}
NODE add(NODE first1, NODE first2)
{
    NODE res = NULL,temp;
    int sum = 0, c = 0,op1,op2;
    while (first1 != NULL || first2 != NULL)
    {
        (first1==NULL)?op1=0:(op1=first1->value);
        (first2==NULL)?op2=0:(op2=first2->value);
        sum = op1 + op2 + c;
        if (sum >= 10)
        {
            c = 1;
        }
        else
        {
            c = 0;
        }
        sum %= 10;
        res=insert_beg(res,sum);
        if(first1!=NULL)
            first1=first1->next;
        if(first2!=NULL)
            first2=first2->next;
    }
    return res;
}
void main()
{
    char nums[20];
    int i,n;
    NODE first1 = NULL, first2 = NULL, result = NULL;
    printf("Enter the first number\n");
    scanf("%s", nums);
    for (i = 0; nums[i] != '\0'; i++)
    {
        n=nums[i]-48;
        first1 = insert_beg(first1, n);
    }
    display(first1);
    printf("Enter the second number\n");
    scanf("%s", nums);
    for (i = 0; nums[i] != '\0'; i++)
    {
        n=nums[i]-48;
        first2 = insert_beg(first2, n);
    }
    display(first2);
    result=add(first1,first2);
    printf("\n");
    display(result);

}