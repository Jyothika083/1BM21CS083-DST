#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coeff;
    int exp;
	struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\nMemory not allocated");
		return NULL;
	}
	return temp;
}
NODE insert_end(NODE first,int c,int e)
{
	NODE new,last;
	new=getnode();
	new->coeff=c;
    new->exp=e;
	new->next=NULL;
	if(first==NULL)
	{
		return new;
	}
	if(first->next==NULL)
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
NODE addpoly(NODE head1,NODE head2)
{
    NODE res,first1=head1,first2=head2;
    while (first1!=NULL && first2!=NULL)
    {
        if(first1->exp==first2->exp)
        {
            res=insert_end(res,first1->coeff+first2->coeff,first1->exp);
            first1=first1->next;
            first2=first2->next;
        }
        else
        {
            if(first1->exp>first2->exp)
            {
                res=insert_end(res,first1->coeff,first1->exp);
                first1=first1->next;
            }
            else
            {
                res=insert_end(res,first2->coeff,first2->exp);
                first2=first2->next;
            }
        }
    }
    while (first1!=NULL)
    {
        res=insert_end(res,first1->coeff,first1->exp);
        first1=first1->next;
    }
    while(first2!=NULL)
    {
        res=insert_end(res,first2->coeff,first2->exp);
        first2=first2->next;
    }
    return res;
    
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
		printf("%dx%d\t",temp->coeff,temp->exp);
        
		temp=temp->next;
	}
	printf("\n");
}
void main()
{
    NODE first1=NULL,first2=NULL,res=NULL;
    first1=insert_end(first1,3,3);
    //first1=insert_end(first1,4,1);
    first1=insert_end(first1,1,0);
    first2=insert_end(first2,2,2);
    first2=insert_end(first2,3,1);
    first2=insert_end(first2,2,0);
    display(first1);
    display(first2);
    res=addpoly(first1,first2);
    display(res);

    
}
