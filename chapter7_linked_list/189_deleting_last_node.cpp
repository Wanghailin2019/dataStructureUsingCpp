/********************************************************
    Filename:189_deleting_last_node.cpp
    Author name: Timothy
    Time:2021/08/06
    Version:v1
    Description:
          删除单链表的尾节点。
          删除一个尾节点要比添加一个尾节点要复杂，首先需要知道尾节点和倒数第一个节点的位置，否则删除的尾节点的前一个节点不能指向null。
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
    int n = 0;
    node = start.next;
    previous = &start;
    if (node == NULL)
        cout<<"\n Underflow";
    else
    while(node)
    {
        node = node->next;
        previous = previous->next;
        n++;  //获取节点总的个数
    }
    cout<<"\n totally have "<<n<<" nodes."<<endl;
    node = start.next;
    previous = &start;
    while(n != 1)  //获取尾节点和倒数第二个节点的位置
    {
        node = node->next;
        previous = previous->next;
        n --;
    }
    previous->next = node->next;
    free(node);
}