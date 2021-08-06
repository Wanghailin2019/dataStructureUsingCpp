/********************************************************
    Filename:108_push_pop_tranverse_using_stl.cpp
    Author name: Timothy
    Time:2021/08/04
    Version:v1
    Description:
         Perform the PUSH,POP, and TRAVERSE operation with the STACK, using STL
    ps: 使用堆栈的标注库方法，代码量明显降低很多，直接用stack <int> myStack;
*********************************************************/

#include <iostream>
#include <stack>
using namespace std;
int main ()
{
    stack <int> myStack;
    int n,opt;
    while(1)
    {
        cout<<endl<<"1. PUSH 2. POP 3. SIZE OF STACK 4. TOP OF STACK 5. QUIT    ";
        cin>>opt;
        if(opt==1)
        {
            cout<<endl<<"Enter a number to push: ";
            cin>>n;
            myStack.push(n);
        }
        else
        if(opt==2)
        {
            if(myStack.empty())
                cout<<endl<<"Underflow";
            else
            {
                myStack.pop();
                cout<<endl<<"Pop operation completed successfully!";
            }
        }
        else
        if(opt==3)
        {
            cout<<endl<<myStack.size()<<" elements are in stack";
        }
        else
        if(opt==4)
        {
            if(myStack.empty())
                cout<<endl<<"NO ELEMENTS ARE IN STACK!";
            else
            cout<<endl<<"The top value is :"<<myStack.top();
        }
        else
        if(opt==5)
            exit(0);
        else
            cout<<endl<<"Invalid choice";
    }
    return 0;
}