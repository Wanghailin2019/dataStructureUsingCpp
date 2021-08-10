/********************************************************
    Filename:216_double_linked_list_creation.cpp
    Author name: Timothy
    Time:2021/08/10
    Version:v1
    Description:
          Creation of Double Linked List.
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

struct link start;

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
int main()
{
    struct link *node;
    create(node);
    cout<<"\n AFTER CREATING THE LINKED LIST IS \n";
    display(node);
}