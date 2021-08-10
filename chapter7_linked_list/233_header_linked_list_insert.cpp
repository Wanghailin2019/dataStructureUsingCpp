/********************************************************
    Filename:233_header_linked_list_insert.cpp
    Author name: Timothy
    Time:2021/08/10
    Version:v1
    Description:
           Inserting a Node Into a Header Linked List
           注：未调试成功！
*********************************************************/

# include <iostream>
#include<iomanip>
# include <cstdlib>
using namespace std;
struct link
{
    int info;
    struct link *next;
};
int i;
int number;
struct link *start, *New;
void insert(struct link *);
void create(struct link *);
void display(struct link *);

void create(struct link *node)
{
    char ch='y';
    start->next = NULL; /* Empty list */
    node = start; /* Point to the header node of the list */
    node->next = (struct link* ) malloc(sizeof(struct link)); /* Create header node */
    i = 0;
    while(ch == 'y' || ch=='Y')
    {
        node->next = (struct link* )malloc(sizeof(struct link));
        node = node->next;
        cout<<"\nENTER THE NUMBER: ";
        cin>>node->info;
        node->next = NULL;
//        fflush(stdin);
        cout<<"\nDO YOU WANT TO CREATE MORE NODES[Y/N]";
        cin>>ch;
        i++;
    }
    cout<<"\n NUMBER OF NODES : "<<i;
    node = start;
    node->info = i; /*ASSIGN TOTAL NUMBER OF NODES INTO THE HEADER LIST*/
}
void insert(struct link *node)
{
    int n = 1;
    int no,count;
    node=start;
    count = node->info;
    node = node->next;
    cout<<"\nENTER THE NODE NUMBER TO INSERT : ";
//    fflush(stdin);
    cin>>no;
    while(count)
    {
        if(n == no)
        {
            New = (struct link* )malloc(sizeof(struct link));
            New->next = node->next ;
            node->next = New;
            cout<<"\nENTER THE VALUE";
//            fflush(stdin);
            cin>>New->info;
            node = node->next;
        }
        else
        {
            node = node->next;
            count--;
        }
        n++;
    }
    node = start;
    node->info = node->info+1;
}
void display(struct link *node)
{
    int count;
    node=start;
    count = node->info;
    node = node->next;
    cout<<"\n THE LINKED LIST IS \n";
    while (count)
    {
        cout<<node->info;
        node = node->next;
        count --;
    }
}
int main()
{
    struct link *node;
//    clrscr();
    create(node);
    display(node);
    insert (node);
    display(node);
    return 0;
}
