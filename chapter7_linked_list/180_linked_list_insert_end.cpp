/********************************************************
    Filename:180_linked_list_insert_end.cpp
    Author name: Timothy
    Time:2021/08/06
    Version:v1
    Description:
          Insert a Node Into a Simple Linked List at the End of the list.
*********************************************************/

#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

struct list
{
    int info;
    struct list *next;
};
struct list start, *first, *New,*last;

/* Function main */
void create(struct list *);
void display (struct list *);
void insert(struct list *);

int main()
{
    struct list *node;
    create(node);
    insert(node);
    display(node);
}

void create(struct list *node) /*LOGIC TO CREATE A LINK
LIST*/
{
    char ch='y';
    start.next = NULL;
    node = &start; /* Point to the start of the list */
    while(ch =='y' || ch=='Y')
    {
        node->next = (struct list* )
                malloc(sizeof(struct list));
        node = node->next;
        cout<<"\n ENTER A NUMBER : ";
        cin>>node->info;
        node->next = NULL;
        cout<<"\n DO YOU WANT TO CRTEATE MORE NODES(y/n): ";
        cin>>ch;
    }
}

void display(struct list *node)
{ /*DISPLAY THE LINKED LIST*/
    node = start.next;
    cout<<"\n After Inserting a node list is as follows:\n";
    while (node)
    {
        cout<<setw(5)<<node->info;
        node = node->next;
    }
}

void insert(struct list *node)
{ /* LOGIC OF INSERTION(LAST NODE) */
    node = start.next;
    last = &start;
    while(node)
    {
        node = node->next;//便历链表，直到node指向null;last指向链表最后一个节点
        last= last->next;
    }
    if(node == NULL)
    {
        New = (struct list* ) malloc(sizeof(struct list));
        New->next = node ;
        last->next = New;
        cout<<"\n ENTER THE VALUE OF LAST NODE: ";
        cin>>New->info;
    }
}