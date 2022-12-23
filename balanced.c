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
int check()
{
    int i;
    char sym;
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')')
        {
            if(top==-1)
                return 0;
            else
            {
                sym=pop();
                if(!(sym=='(' && exp[i]==')'))
                    return 0;
            }
        }
    }
    if(top==-1)
        return 1;
    else
        return 0;
}
void main()
{
    int result;
    scanf("%s",exp);
    result=check();
    if(result==1)
    {
        printf("yEs");
    }
    if(result==0)
        printf("No");


}
