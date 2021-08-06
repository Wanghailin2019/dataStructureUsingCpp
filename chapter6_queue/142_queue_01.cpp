/********************************************************
    Filename:142_queue_01.cpp
    Author name: Timothy
    Time:2021/08/05
    Version:v1
    Description:
         INSERTION AND DELETION IN A QUEUE ARRAY IMPLEMENTATION.
*********************************************************/
# include<iostream>
#include<stdlib.h>
using namespace std;
int *q,size,front=-1,rear=-1;
void insert(int n)
{
    if(rear == size-1) //size是队列开辟的空间的大小
        cout<<"\n QUEUE OVERFLOW! ";
    else
    {
        rear ++;
        *(q+rear) = n ;
        if(front == -1)
            front = 0;
    }
}

/* Function to delete an element from queue */
void Delete()
{
    if (front == -1)
    {
        cout<<"\n Underflow!";
        return ;
    }
    cout<<"\n Element deleted : "<<*(q+front);
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = front + 1;
}
void display()
{
    int i;
    if (front == -1)
        cout<<"\n EMPTY QUEUE!";
    else
    {
        cout<<"\nTHE QUEUE ELEMENTS ARE";
        for(i = front ; i <= rear; i++)
            cout<<"\t"<<*(q+i);  // \t, Tab
    }
}
int main()
{
    int opt;
    cout<<"\n Enter the size of the QUEUE: ";
    cin>>size;
    q= (int *)malloc(size * sizeof(int)); //在内存空间开辟一个int型的空间，并用指针q指向它
    while(1)
    {
        cout<<"\n Enter the choice";
        cout<<"\n 1.INSERT 2. DELETE 3. DISPLAY 0. EXIT : ";
        cin>>opt;
        if(opt==1)
        {
            cout<<"\n Enter the number to insert";
            cin>>opt;
            insert(opt);
        }
        else
        if(opt==2)
            Delete();
        else
        if(opt==3)
            display();
        else
        if(opt==0)
            exit(0);
        else
            cout<<"\n INVALID CHOICE";
    }
}
