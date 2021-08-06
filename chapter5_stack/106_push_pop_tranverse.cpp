/********************************************************
    Filename:106_push_pop_tranverse.cpp
    Author name: Timothy
    Time:2021/08/04
    Version:v1
    Description:
         Perform the PUSH,POP, and TRAVERSE operation with the STACK.
*********************************************************/

#include<iostream>
#include<stdlib.h>

using namespace std;

static int *s,size,top=-1;

//method to push an integer into stack
void push(int no)
{
    if(top == size-1)
        cout<<"\n STACK OVERFLOW ";
    else
    {
        top = top+1;
        *(s+top) = no;
    }
}

//method to pop an element from stack
void pop()
{
    if(top == -1)
        cout<<"\n STACK UNDERFLOW ";
    else
    {
        cout<<*(s+top)<< " IS DELETED";
        --top;
    }
}
//method to display the elements of the stack
void traverse()
{
    int i;
    if(top == -1)
        cout<<"\n STACK IS EMPTY ";
    else
    for(i = top; i>=0;i--)
        cout<<*(s+i)<<" ";
}
//driver program
int main()
{
    int opt;
    cout<<"\n Enter the size of the stack: ";
    cin>>size; //ask user about the size of stack
    s= (int *)malloc(size * sizeof(int)); //dynamically allocate memory for stack
//infinite loop to handle the operations of stack
    while(1)
    {
        cout<<"\n Enter the choice ";
        cout<<" \n 1.PUSH 2. POP 3. DISPLAY 0. EXIT ";
        cin>>opt;
        if(opt==1)
        {
            cout<<"\n Enter the number to insert: ";
            cin>>opt;
            push(opt);
        }
        else
        if(opt==2)
            pop();
        else
        if(opt==3)
            traverse();
        else
        if(opt==0)
            exit(0);
        else
            cout<<"\n INVALID CHOICE";
    }
    return 0;
}
