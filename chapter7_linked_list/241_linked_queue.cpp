/********************************************************
    Filename:241_linked_queue.c
    Author name: Timothy
    Time:2021/08/10
    Version:v1
    Description:
           program for linked queue.
*********************************************************/

#include<stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;
struct Q
{
    int info;
    struct Q *next;
};
struct Q *front,*rear,*New;
void insert()
{
    New = (struct Q *)malloc(sizeof(struct Q));
    cout<<"\n Enter a number: ";
    cin>>New->info;
    New ->next = NULL;
    if(front == NULL)
    {
        front = New;
        rear = New;
    }
    else
    {
        rear->next = New;
        rear = rear->next;
    }
}
void delet()
{
    if(front == NULL)
    {
        cout<<"\n QUEUE IS EMPTY";
        return;
    }
    New = front;
    if(New != NULL)
    {
        cout<<New->info<<" IS DELETED",New->info;
        front = front-> next;
        free(New);
    }
}
void display()
{
    New = front;
    if(New == NULL)
    {
        cout<<"\n QUEUE IS EMPTY";
        return;
    }
    cout<<"\n THE QUEUE IS ";
    while(New != NULL)
    {
        cout<<setw(5)<<New->info;
        New = New->next;
    }
}
int main()
{
    int opt;
    while(1)
    {
        cout<<"\n 1. INSERT 2. DELETE 0. EXIT";
        cin>>opt;
        if(opt==1)
        {
            insert();
            cout<<"\n AFTER INSERTION THE QUEUE IS :";
            display();
        }
        else
        if(opt==2)
        {
            delet();
            cout<<"\n AFTER DELETE THE QUEUE IS: ";
            display();
        }
        else
        if(opt==0)
            exit(0);
    }
}
