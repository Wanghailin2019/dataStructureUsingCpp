/********************************************************
    Filename:180_linked_list_insert_known_node_02.cpp
    Author name: Timothy
    Time:2021/08/06
    Version:v1
    Description:
          Insert a Node Into a Simple Linked List Information Is Known and Put After Some Specified Node.
          这段代码实现在已知的链表中，第一个大于或等于输入值的节点后插入该数值的节点。
          例如：
          输入链表：12 32 85 95 4
          插入值：96
          返回链表：12 32 85 95 96 4
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

struct link start, *first, *New,*before;

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
{
//    int no= 0;
    int ins;
    node = start.next;
    before = &start;
    cout<<"\n Input value node the node you want to insert:";
    fflush(stdin);  //输入清空缓冲区
    cin>>ins;
    while(node)
    {
        if(node->info >= ins)
        {
            New = (struct link* ) malloc(sizeof(struct link));
            New->next = node;
            before->next = New;
            New->info = ins;
            break ;
        }
        else
        {
            node = node->next;
            before= before->next;
        }
//        no++;
    }
}