/********************************************************
    Filename:237_circular_linked_list.c
    Author name: Timothy
    Time:2021/08/10
    Version:v1
    Description:
           Creating Circular Header Linked List.
           注：代码逻辑有一些问题！
*********************************************************/

# include <stdio.h>
# include <stdlib.h>
# include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
struct link
{
    int info;
    struct link *next;
};
int i; /* Represents number of nodes in the list */
int number=0;
struct link start,*node, *new1;

void create()
{
    char ch;
    node = &start; /* Point to the header node in the list */
    i = 0;
    do
    {
        node->next = (struct link* ) malloc(sizeof(struct link));
        node = node->next;
        cout<<"\n Input the node"<<i+1<<": ";
//        fflush(stdin);
//        fflush(stdout);
        cin>>node->info;
//        fflush(stdout);
        cout<<"\n DO YOU WANT TO CREATE MORE[Y/N] ";
        cin>>ch;
        i++;
    }while(ch=='y' || ch=='Y');
    node->next = &start;
    start.info = i; /* Assign total number of nodes to the header node */
}
void insertion()
{
    struct link *first;
    first=&start;
    node=start.next;
    int opt;
    int count = node->info;
    int node_number = 1;
    int insert_node;
    node = node->next;
    cout<<"\n Input node number you want to insert. ";
    cout<<"\n Value should be less are equal to the";
    cout<<"\n number of nodes in the list: ";
    cin>>insert_node;
    while(count--)
    {
        if(node_number == insert_node)
        {
            new1 = (struct link* )malloc(sizeof(struct link));
            first->next=new1;
            new1->next = node;
            cout<<"\n Input the node value: ";
            cin>>new1->info;
            opt=1;
            break;
        }
        else
        {
            node = node->next;
            first=first->next;
        }
        node_number ++;
    }
    if (opt==1)
    {
        node = &start; /* Points to header node */
        node->info = node->info+1;
    }
}
/* Display the list */
void display()
{
    node=&start;
    int count = node->info;
    do
    {
        cout<<setw(5)<<node->info;  //使用setw()函数需要包含头文件<iomanip>
        node = node->next;
    }while(count--);
}
int main()
{
    create();
    cout<<"\n Before inserting a node list is as follows:\n";
    display();
    insertion();
    cout<<"\n After inserting a node list is as follows:\n";
    display();
}

