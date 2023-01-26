#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    struct node *right;
    int value;
};
typedef struct node* NODE;
NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Memory not allocated\n");
        return NULL;
    }
    printf("Enter the item to be inserted :");
    scanf("%d",&temp->value);
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void insert(NODE root,NODE temp)
{
    if(temp->value<root->value)
    {
        if(root->left!=NULL)
            insert(root->left,temp);
        else
            root->left=temp;
    }
    if(temp->value>root->value)
    {
        if(root->right!=NULL)
            insert(root->right,temp);
        else
            root->right=temp;
    }
}
void traverseInorder(NODE root)  
{  
    if (root == NULL)  
        return;  
    traverseInorder(root->left);  
    printf(" %d ", root->value);  
    traverseInorder(root->right);  
}  
void traversePreorder(NODE root)  
{  
    if (root == NULL)  
        return;  
    printf(" %d ", root->value);  
    traversePreorder(root->left);  
    traversePreorder(root->right);  
}  
void traversePostorder(NODE root)  
{  
    if (root == NULL)  
        return;    
    traversePostorder(root->left);  
    traversePostorder(root->right);  
    printf(" %d ", root->value);
}  
void main()
{
    NODE root=NULL,temp=NULL;
    char ch;
    do
    {
        temp=getnode();
        if(root==NULL)
            root=temp;
        else
            insert(root,temp);
        printf("Do you want to enter more(y/n) :");
        getchar();
        scanf("%c",&ch);
        printf("\n");
    } while (ch=='y' || ch=='Y');
        
    printf("Inorder :");
    traverseInorder(root);
    printf("\n");
    printf("Postorder :");
    traversePostorder(root);
    printf("\n");
    printf("Preorder :");
    traversePreorder(root);
    printf("\n");
}
