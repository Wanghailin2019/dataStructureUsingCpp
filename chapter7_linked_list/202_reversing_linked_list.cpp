/********************************************************
    Filename:202_reversing_linked_list.cpp
    Author name: Timothy
    Time:2021/08/06
    Version:v1
    Description:
          Reversing a linked list.
*********************************************************/

#include<iostream>
using namespace std;

struct link
{
    int info;
    struct link *next;
};
int i, no;
struct link *start, *node, *previous, *current, *counter;
void display(struct link *);
void create(struct link *);
struct link * reverse(struct link *);

int main()
{
    struct link *node;
    struct link *p;
    node = (struct link *) malloc(sizeof(struct link));
    create(node);
    cout<<"\n Original List is as follows: ";
    display(node);
    p = (struct link *)malloc(sizeof(struct link));
    p = reverse(node);
    cout<<"\n After reverse operation list is as follows: ";
    display(p);
    return 0;
}
struct link * reverse(struct link *start)
{
    current = start;
    previous = NULL ;
    while( current != NULL )
    {
//        counter = (struct link *)malloc(sizeof(struct link));
        counter = current->next ;  //采用迭代的方法反转列表，每一步借助节点current，counter和previous反转指针的指向。
        current->next = previous ;
        previous = current ;
        current = counter;
    }
    start = previous; //最后把原先（未反转）的链表的尾作为头，返回该节点
    return(start);
}
void display(struct link *node)
{
    while (node != NULL)
    {
        cout<<node->info<<" ";
        node = node->next;
    }
}
void create(struct link *node)
{
    int i;
    int no;
    cout<<"\n Input the number of nodes you want to create : ";
    cin>>no;
    for (i = 0; i < no ; i++)
    {
        cout<<"\nEnter the number : ";
        cin>>node->info;
        node->next = (struct link* ) malloc(sizeof(struct link));
        if( i == no - 1)
            node->next = NULL;
        else
            node = node->next;
    }
    node->next = NULL;
}