/********************************************************
    Filename:226_double_linked_list_delete01.cpp
    Author name: Timothy
    Time:2021/08/10
    Version:v1
    Description:
           Delete First Node From a Double Linked List.
          双链表删除首节点(尾结点见注释）
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
void Delete(struct link *);

void create(struct link *node)
{
    char ch='y';
    start.next = NULL; /* Empty list */
    start.previous = NULL;
    node = &start; /* Point to the start of the list */
    while( ch == 'y' || ch=='Y')
    {
        node->next = (struct link *)malloc(sizeof(struct link));
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
    int n;
    cout<<"\nENTER THE INFORMATION VALUE TO INSERT";
    cin>>n;
    node = start.next;
    while(node)
    {
        if(node->info >= n)
        {
            New=(struct link *)malloc(sizeof(struct link));
            New->info = n;
            New->next = node;
            New->previous = node->previous;
            node->previous->next = New;
            node->previous = New;
            break;
        }
        else
        {
            node=node->next;
        }
    }
}

void Delete(struct link *node)
{
    node = start.next;
    if(node == NULL)
    {
        cout<<"\n Underflow!";
    } else{
        node->previous->next = node->next;
        node->next->previous = node->previous;
        free(node);
    }
}

///* 删除尾结点 */
//void Delete(struct link *node)
//{
//    int n=0;
//    node = start.next;
//    if( node == NULL)
//    {
//        cout<<"\n Underflow";
//    }
//    else
//        while(node->next)
//        {
//            node = node->next;
//            n++;
//        }
//    node = start.next;
//    while(n != 1)
//    {
//        node = node->next;
//        n--;
//    }
//    node=node->next;
//    node->previous->next = NULL;
//    free(node);
//}

int main()
{
    struct link *node;
    create(node);
    cout<<"\n AFTER CREATING THE LINKED LIST IS : \n";
    display(node);
//    insert(node);
//    cout<<"\n List after insertion :  \n";
//    display(node);
    Delete(node);
    cout<<"\n list of deletion of first node \n";
    display(node);
}





