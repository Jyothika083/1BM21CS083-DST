#include<stdio.h>
#include<string.h>
#define size 10
char exp[size];
char s[size];
int top=-1;
void push(char item)
{
    top++;
    s[top]=item;
}
char pop()
{
    if(top==-1)
    {
        printf("empty");

    }
    return s[top--];
}
void main()
{
    int i,result;
    char sym;
    scanf("%s",exp);
    for(i=0;i<strlen(exp);i++)
    {
        sym=exp[i];
        if(sym=='(')
        {
            push(sym);
        }
        else{
            if(top==-1)
            {
                result=0;
                break;
            }
            if(pop()!='(')
            {
                result=0;
                break;

            }
             
        }
    }
    if(top==-1)
    {
        result=1;
    }
    else
        result=0;
    if(result==1)
    {
        printf("yEs");
    }
    if(result==0)
        printf("No");


}