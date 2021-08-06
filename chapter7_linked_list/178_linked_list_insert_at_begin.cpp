/********************************************************
    Filename:178_linked_list_insert_at_begin.cpp
    Author name: Timothy
    Time:2021/08/05
    Version:v1
    Description:
          Insert a Node Into a Simple Linked List at the Beginning.
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

struct list start, *first, *New;

/* Function main */
void create(struct list *node) /*LOGIC TO CREATE A LINK LIST*/
{
    char ch='y';
    start.next = NULL;
    node = &start; /* Point to the start of the list */
    while(ch =='y' || ch=='Y')
    {
        node->next = (struct list* ) malloc(sizeof(struct list));
        node = node->next;
        cout<<"\n ENTER A NUMBER OF LINKED LIST : ";
        cin>>node->info;
        node->next = NULL;
        cout<<"\n DO YOU WANT TO CRTEATE MORE NODES : ";
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
{ /*INSERT AN ELEMENT AT THE FIRST NODE*/
    node = start.next;
    first = &start;
    New = (struct list* ) malloc(sizeof(struct list));
    New->next = node ;
    first->next = New;
    cout<<"\n Input the fisrt node value: ";
    cin>>New->info;
}

int main()
{
    struct list *node;
    create(node);
    insert(node);
    display(node);
}


