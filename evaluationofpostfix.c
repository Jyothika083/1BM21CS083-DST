#include<stdio.h>
#include<ctype.h>
#include<string.h>

void push(int s[],int *top,int item)
{
    s[++(*top)]=item;
}
int pop(int s[],int *top)
{
    return s[(*top)--];
}
void display(int s[],int *top)
{
    int i;
    if(*top==-1)
        printf("empty\n");
    else{
        for(i=0;i<=*top;i++)
        {
            printf("%d\t",s[i]);
        }   
     }
}
int eval(char postfix[],int s[],int *top)
{
    int i,op1,op2;
    char sym;
    for(i=0;i<strlen(postfix);i++)
    {
        sym=postfix[i];
        if (isdigit(sym))
        {
            push(s,top,(int)(sym)-48);
        }
        else
        {
            op1=pop(s,top);
            op2=pop(s,top);
            switch(sym)
            {
                case '+':push(s,top,(op2+op1));
                        break;
                case '-':push(s,top,(op2-op1));
                        break;
                case '*':push(s,top,(op2*op1));
                        break;
                case '/':push(s,top,(op2/op1));
                        break;

            }
        }
        display(s,top);
        printf("\n");
    }
    return (s[*top]);
}
void main()
{
    int top=-1;
    int s[20];
    char postfix[20];
    int r;
    printf("enter a postfix expression \n");
    scanf("%s",postfix);
    r=eval(postfix,s,&top);
    printf("result=%d",r);
}