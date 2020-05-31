/*This program creates a binary search tree and insert the given set of names into it*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

struct node
{
    struct node *lchild;
    char names[MAX];
    struct node *rchild;
};

struct node *getnode(char name[]);//This function allocates storage for a new node
struct node *insert(struct node *root,char name[]);//This function inserts a new node in the BST
void display(struct node *p,int level);//This  function displays the BST(from left  to right)

int main()
{
    struct node *root=NULL;//Root node of the tree
    int choice;//Stores choice of the user
    char name[MAX];//String to store name
    /*Below is a infinite while loop which displays a menu and allows the user to choose an option from the given menu*/
    while(1)
    {
        printf("\n1.Display the tree");
        printf("\n2.Insert a node");
        printf("\n3.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            display(root,0);
            break;
        case 2:
            printf("Enter the name to be inserted:");
            scanf("%s",name);
            root=insert(root,name);
            break;
        case 3:
            exit(0);//Program ends
        }
    }
}
struct node *getnode(char name[])
{
    struct node *p=(struct node*)malloc(sizeof(struct node));//Allocate a new node using malloc
    strcpy(p->names,name);//Stores the name in the newly allocated node
    p->lchild=p->rchild=NULL;//Left child and right child of the newly allocated node points to null
    return p;//returns the newly allocated node
}
struct node *insert(struct node *root,char name[])
{
    struct node *temp,*p,*par;//Deceleration of the helper pointers
    p=root;
    par=NULL;//Par will points to the parent of the node pointed by p
    /*While loop given below finds proper position for the new node in the tree*/
    while(p!=NULL)
    {
        par=p;
        if(strcmp(name,p->names)==1)//If the value of the new node is greater than the value of node pointed by p then move right in the tree
            p=p->rchild;
        else if(strcmp(name,p->names)==-1)//If the value of the new node is smaller than the value of node pointed by p then move left in the tree
            p=p->lchild;
        else//If node is present in the tree
        {
            printf("Key already present in the tree");
            return root;
        }
    }
    temp=getnode(name);//Allocates a node for the value to be inserted in the tree
    if(par==NULL)//If tree is empty allocated new node will become the root node
        root=temp;
    else if(strcmp(name,par->names)==1)//If the value of the new node is greater than the value of the par node than new node is inserted to the right of par node
        par->rchild=temp;
    else//If the value of the new node is smaller than the value of the par node than new node is inserted to the left of par node
        par->lchild=temp;
    return root;//returns the root of the tree
}
void display(struct node *p,int level)
{
    if(p==NULL)
        return;
    display(p->rchild,level+1);
    printf("\n");
    for(int i=0;i<level;i++)
        printf("           ");
    printf("%s",p->names);
    display(p->lchild,level+1);
}

