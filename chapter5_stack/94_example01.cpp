/********************************************************
    Filename:94_example01.cpp
    Author name: Timothy
    Time:2021/08/04
    Version:v1
    Description:
         check the correctness of the PARENTHESIS of an expression
        by using STACK.
*********************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//declare the top
static int top = -1;
//declare the stack
char stack[25];
//definition for push()
void push(char no)
{
//condition for overflow
    if(top == 24)
        cout<<endl<<"STACK OVERFLOW";
    else
    { //insert the open grouping character into stack
        top = top+1; //increase the value of top
        stack[top] = no; //stare the character to stack
    }}
//definition of pop()
void pop(char ch)
{
    if(top == -1) //condition for underflow
    {
        cout<<"\n STACK UNDERFLOW";
        cout<<"\n INVALID EXPRESSION";
        exit(0);
    }
//pop the character if proper closing character is found
    if(ch==')' && stack[top]=='(' || ch==']' && stack[top]=='['
    || ch=='}' & stack[top]=='{')
        --top; //decrease the value of top
}


int main()
{
    string str;
    cout<<"\n ENTER THE EXPRESSION: ";
    cin>>str;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='('||str[i]=='['||str[i]=='{')
            push(str[i]);
        if(str[i]== ')'|| str[i]==']' || str[i]=='}')
            pop(str[i]);
    }
    if(top == -1)
        cout<<"\n EQUATION IS CORRECT";
    else
    cout<<"\n INVALID EXPRESSION";

    return 0;
}