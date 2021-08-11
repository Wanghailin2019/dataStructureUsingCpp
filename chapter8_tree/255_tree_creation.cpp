/********************************************************
    Filename:255_tree_creation
    Author name: Timothy
    Time:2021/08/11
    Version:v1
    Description:
           Creation of a Tree.
*********************************************************/

//#include<stdio.h>
//#include<alloc.h>
#include<iostream>
using namespace std;
struct node
{
    int info;
    struct node *left;
    struct node *right;
};
struct node *create(int , struct node *);
void display(struct node *, int );
int main()
{
    int info ;
    char ch='y';
    struct node *tree ;
    tree = NULL;
    while(ch == 'y' || ch=='Y')
    {
        cout<<"\n Input information of the node: ";
        cin>>info;
        tree = create(info, tree);
        cout<<"\n Tree is ";
        display(tree, 1);
        cout<<"\nDO YOU WANT TO CREATE MORE CHILDS[Y/N]: ";
        cin>>ch;
    }
    return 0;
}
struct node * create(int info, struct node *n)
{
    if (n == NULL)
    {
        n = (struct node *) malloc(sizeof(struct node ));
        n->info = info;
        n->left = NULL;
        n->right= NULL;
        return (n);
    }
    if (n->info >= info )
        n->left = create(info, n->left);
    else
        n->right = create(info, n->right); return(n);
}
void display(struct node *tree, int no)
{
    int i;
    if (tree)
    {
        display(tree->right, no+1);
        cout<<"\n ";
        for (i = 0; i < no; i++)
            cout<<" ";
        cout<<tree->info;
        cout<<"\n";
        display(tree->left, no+1);
    }
}