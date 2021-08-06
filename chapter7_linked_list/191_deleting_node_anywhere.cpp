/********************************************************
    Filename:191_deleting_node_anywhere.cpp
    Author name: Timothy
    Time:2021/08/06
    Version:v1
    Description:
          删除单链表的任意位置节点。
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

struct link start, *previous,*node;

/* Function main */
void create(struct link *);
void display (struct link *);
void delet(struct link *);

int main()
{
    create(node);
    printf("\n THE CREATED LINKED LIST IS :\n");
    display(node);
    delet(node);
    printf("\n AFTER DELETING THE FIRST NODE THE LINKED LIST IS ");
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

void delet(struct link *node)
{
    int n = 1;
    int pos;
    node = start.next;
    previous = &start;
    cout<<"\n Input node number you want to delete:";
    cin>>pos;
    while(node)
    {
        if(n == pos)
        {
            previous->next = node->next;
            free(node);
            break ;
        }
        else
        {
            node = node->next;
            previous = previous->next;
        }
        n++;
    }
}