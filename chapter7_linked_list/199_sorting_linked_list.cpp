/********************************************************
    Filename:199_sorting_linked_list.cpp
    Author name: Timothy
    Time:2021/08/06
    Version:v1
    Description:
          Sorting a Linked List in Ascending Order.
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

struct link start, *New,*node,*temp;

/* Function main */
void create(struct link *);
void display (struct link *);
void sort(struct link *);

int main()
{
    create(node);
    cout<<"\n THE CREATED LINKED LIST IS :\n";
    display(node);
    sort(node);
    cout<<"\n AFTER SORT THE LINKED LIST IS :\n";
    display(node);
}
void create(struct link *node) /*LOGIC TO CREATE A LINK LIST*/
{
    char ch='y';
    start.next = NULL;
    node = &start; /* Point to the start of the list */
    while(ch =='y' || ch=='Y')
    {
        node->next = (struct link* ) malloc(sizeof(struct
                link));
        node = node->next;
        cout<<"\n ENTER A NUMBER : ";
        cin>>node->info;
        node->next = NULL;
        cout<<"\n DO YOU WANT TO CRTEATE MORE NODES: ";
        cin>>ch;
    }
}
void display(struct link *node)
{ /*DISPLAY THE LINKED LIST*/
    node = start.next;
    while (node)
    {
        cout<<setw(5)<<node->info;
        node = node->next;
    }
}

void sort(struct link *node)
{
    /* 冒泡排序 */
    for(New = start.next; New->next != NULL; New = New->next)
    {
        for(temp = New->next; temp != NULL; temp = temp->next)
        {
            if(New->info > temp->info)
            {
                int t = New->info;
                New->info = temp->info;
                temp->info = t;
            }
        }
    }
}