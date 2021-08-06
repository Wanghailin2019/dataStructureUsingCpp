/********************************************************
    Filename:177_linked_list_creation.cpp
    Author name: Timothy
    Time:2021/08/05
    Version:v1
    Description:
         Create a linked list.
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

struct link start;

/* Function main */
void create(struct link *node) /*LOGIC TO CREATE A LINK LIST*/
{
    char ch='y';
    start.next = NULL;
    node = &start; /* Point to the start of the list */
    while(ch =='y' || ch=='Y')
    {
        node->next = (struct link* ) malloc(sizeof(struct link));
        node = node->next;
        cout<<"\n ENTER A NUMBER FOR LINKED LIST: ";
        cin>>node->info;
        node->next = NULL;
        cout<<"\n DO YOU WANT TO CREATE MORE NODES(y/n): ";
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


int main()
{
    struct link *node;
    create(node);
    display(node);
}

