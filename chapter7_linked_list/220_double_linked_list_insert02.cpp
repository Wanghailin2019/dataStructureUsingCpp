/********************************************************
    Filename:220_double_linked_list_insert02.cpp
    Author name: Timothy
    Time:2021/08/10
    Version:v1
    Description:
          Inserting a Node in the Doubly Linked List When Node Number Is Known.
          已知插入的位置，插入节点
          例如：
          已知双链表：3，6,7,8,9
          输入插入位置：2
          输入插入值：4
          插入后链表输入：3,4,6,7,8,9
*********************************************************/

#include <iostream>
#include<iomanip>
# include <cstdlib>
using namespace std;

struct link
{
    int info;
    struct link *next;
    struct link *previous;
};

struct link start,*New;

void create (struct link *);
void display (struct link *);

void create(struct link *node)
{
    char ch='y';
    start.next = NULL; /* Empty list */
    start.previous = NULL;
    node = &start; /* Point to the start of the list */
    while( ch == 'y' || ch=='Y')
    {
        node->next = (struct link *)
                malloc(sizeof(struct link));
        node->next->previous = node;
        node = node->next;
        cout<<"\n ENTER THE NUMBER";
        fflush(stdin);
        cin>>node->info;
        node->next = NULL;
        fflush(stdin);
        cout<<"\nDO YOU WANT TO CREATE MORE NODES[Y/N] ";
        fflush(stdin);
        cin>>ch;
    }
}

void display (struct link *node)
{
    node = start.next;
    cout<<endl<<"Link list elements printing in Forward Direction\n";
    while(node->next)
    {
        cout<<setw(5)<<node->info;
        node = node->next;
    }
    cout<<setw(5)<<node->info;
    cout<<endl<<"Link list elements printing in Backward Direction\n";
    do {
        cout<<setw(5)<<node->info;
        node = node->previous;
    } while (node->previous);
}
void insert(struct link *node)
{
    int n,i;
    cout<<"\nENTER THE NODE NUMBER TO INSERT ";
    cin>>n;
    i=1;
    node = start.next;
    New = (struct link *)malloc(sizeof(struct link ));
    fflush(stdin);
    cout<<"\n ENTER THE VALUE TO INSERT ";
    cin>>New->info;
    while(node)
    {
        if(i==n)
        {
            New->next = node;
            New->previous = node->previous;
            node->previous->next = New;
            node->previous = New;
            break;
        }
        else
        {
            node=node->next;
            i++;
        }
    }
}
int main()
{
    struct link *node;
    create(node);
    cout<<"\n AFTER CREATING THE LINKED LIST IS : \n";
    display(node);
    insert(node);
    cout<<"\n List after insertion :  \n";
    display(node);
}

