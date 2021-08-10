/********************************************************
    Filename:243_linked_stack.c
    Author name: Timothy
    Time:2021/08/10
    Version:v1
    Description:
           program for linked stack.
*********************************************************/

#include<stdio.h>
#include<dos.h>
#include<iostream>
using namespace std;

struct stack
{
    int info;
    struct stack *next;
};
struct stack *start=NULL,*node, *first,*New;
void push()
{
    New = (struct stack *)malloc(sizeof(struct stack));
    cout<<"\n Enter a number: ";
    cin>>New->info;
    if(start == NULL)
    {
        start = New;
        New->next = NULL;
    }
    else
    {
        New->next = start;
        start = New;
    }
}
void pop()
{
    first = start;
    if(start == NULL)
        cout<<"\n STACK IS EMPTY!";
    else
    {
        start = start->next;
        cout<<first->info<<" IS POPPED";
        free(first);
    }
}
void traverse()
{
    if(start == NULL)
        cout<<"\n EMPTY STACK";
    else
    {
        first = start;
        while(first)
        {
            cout<<first->info<<" ";
            first = first->next;
        }
    }
}
int main()
{
    int opt;
    while(1)
    {
        cout<<"\n 1. PUSH 2. POP 0.EXIT  ";
        cin>>opt;
        if(opt==1)
        {
            push();
            cout<<"\n AFTER PUSH THE STACK IS ";
            traverse();
        }
        else
        if(opt==2)
        {
            pop();
            cout<<"\n AFTER DELETE THE STACK IS ";
            traverse();
        }
        else
        if(opt==0)
            exit(0);
    }
}
