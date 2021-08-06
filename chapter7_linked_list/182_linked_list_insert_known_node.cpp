/********************************************************
    Filename:180_linked_list_insert_known_node.cpp
    Author name: Timothy
    Time:2021/08/06
    Version:v1
    Description:
          Insert a Node Into a Simple Linked List When the Node Is Known.
          在指定位置插入节点
*********************************************************/

#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

struct link
{
    int info;
    struct link *next;
};

struct link start, *first, *New,*previous;

/* Function main */
void create(struct link *);
void display (struct link *);
void insert(struct link *);

int main()
{
    struct link *node;
    create(node);
    insert(node);
    display(node);
}

void create(struct link *node) /*LOGIC TO CREATE A LINK LIST*/
{
    char ch='y';
    start.next = NULL;
    node = &start; /* Point to the start of the list */
    while(ch =='y' || ch=='Y')
    {
        node->next = (struct link* )
                malloc(sizeof(struct link));
        node = node->next;
        cout<<"\n ENTER A NUMBER : ";
        cin>>node->info;
        node->next = NULL;
        cout<<"\n DO YOU WANT TO CRTEATE MORE NODES(y/n): ";
        cin>>ch;
    }
}
void display(struct link *node)
{ /*DISPLAY THE LINKED LIST*/
    node = start.next;
    cout<<"\n After Inserting a node list is as follows:\n";
    while (node)
    {
        cout<<setw(5)<<node->info;
        node = node->next;
    }
}

void insert(struct link *node)
{ /* Inserting a node */
    int non = 0;
    int pos;
    node = start.next;
    previous = &start;
    cout<<"\n ENTER THE POSITION TO INSERT:";
    cin>>pos;
    while(node)
    {
        if((non+1) == pos)  //便历直到到达指定的位置
        {
            New = (struct link* ) malloc(sizeof(struct link));
            New->next = node ;
            previous->next = New;
            cout<<endl<<"\n Input the node value: ";
            cin>>New->info;
            break ;
        }
        else
        {
            node = node->next;
            previous= previous->next;
        }
        non++;
    }
}
