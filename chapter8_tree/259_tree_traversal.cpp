/********************************************************
    Filename:259_tree_traversal.cpp
    Author name: Timothy
    Time:2021/08/11
    Version:v1
    Description:
           Binary tree traversal.
*********************************************************/

//# include<stdio.h>
#include<iostream>
using namespace std;
struct link
{
    int info;
    struct link *left;
    struct link *right;
};

struct link *binary(int *list, int lower, int upper)
{
    struct link *node;
    int mid = (lower + upper)/2;
    node = (struct link *) malloc(sizeof(struct link));
    node->info = list [mid];
    if ( lower>= upper)
    {
        node->left = NULL;
        node->right = NULL;
        return (node);
    }
    if (lower <= mid - 1)
        node->left=binary(list, lower, mid - 1);
    else
        node->left = NULL;
    if (mid + 1 <= upper)
        node->right = binary(list, mid + 1, upper);
    else
        node->right = NULL;
    return(node);
}
void output(struct link *t, int level)
{
    int i;
    if (t)
    {
        output(t->right, level+1);
        cout<<"\n";
        for (i = 0; i < level; i++)
//            printf(« «);
            cout<<" ";
        cout<<t->info<<" ";
        output(t->left, level+1);
    }
}
void preorder (struct link *node)
{
    if (node)
    {
        cout<<node->info<<" ";
        preorder(node->left);
        preorder(node->right);
    }
}
void inorder (struct link *node)
{
    if (node)
    {
        inorder(node->left);
        cout<<node->info<<" ";
        inorder(node->right);
    }
}
void postorder (struct link *node)
{
    if (node)
    {
        postorder(node->left);
        postorder(node->right);
        cout<<node->info<<" ";
    }
}
int main()
{
    int list[100];
    int number = 0;
    int info;
    char ch='y';
    struct link *t ;
    t = NULL;
    while(ch == 'y' || ch=='Y')
    {
        cout<<"\n Enter the value of the node";
        cin>>info;
        list[number++] = info;
        cout<<"\nDO YOU WANT TO CREATE MORE NODES[Y/N]: ";
        cin>>ch;
    }
    number --;
    cout<<"\n Number of elements in the list is "<<number;
    t = binary(list, 0, number);
    output(t,1);
    cout<<"\n Pre-order traversal\n";
    preorder (t);
    cout<<"\n In-order traversal\n";
    inorder (t);
    cout<<"\n Post-order traversal\n";
    postorder (t);
    return 0;
}  