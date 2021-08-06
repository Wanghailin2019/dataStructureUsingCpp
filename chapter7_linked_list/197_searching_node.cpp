/********************************************************
    Filename:197_searching_node.cpp
    Author name: Timothy
    Time:2021/08/06
    Version:v1
    Description:
          SEARCH A NODE INTO A SIMPLE LINKED LIST WITH INFORMATION IS KNOWN.
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

struct link start, *new1,*node;

/* Function main */
void create(struct link *);
void display (struct link *);
void search(struct link *);

int main()
{
    create(node);
    cout<<"\n THE CREATED LINKED LIST IS :\n";
    display(node);
    search (node);
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

void search(struct link *node)
{
    int val;
    int flag = 0,n = 0;
    node = &start ;
    cout<<"\n ENTER THE NUMBER TO SEARCH : ";
    cin>>val;
    if (node == NULL)
    {
        cout<<"\n List is empty!";
    }
    while(node)
    {
        if( val == node->info )
        {
            cout<<"\n THE NUMBER "<<val<<" IS AT "<<n<<" POSITION IN THE LIST";
            node = node->next;
            flag = 1;
            break;
        }
        else
        {
            node = node->next;
        }
        n++;
    }
    if(!flag)
    {
        cout<<"\n THE NUMBER %d IS NOT FOUND IN THE LIST"<<val;
    }
}