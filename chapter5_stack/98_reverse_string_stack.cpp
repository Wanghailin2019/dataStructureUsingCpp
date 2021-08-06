/********************************************************
    Filename:98_reverse_string_stack.cpp
    Author name: Timothy
    Time:2021/08/04
    Version:v1
    Description:
         reverse a string by stack
*********************************************************/

#include<iostream>
#include<string.h>
using namespace std;
// A class to represent a stack

class reverse
{
public:
    int top;
    int size;
    char* stk;
};

reverse* BuildStack(unsigned size)
{
    reverse* stack = new reverse();
    stack->size = size;
    stack->top = -1;
    stack->stk = new char[(stack->size *
                           sizeof(char))];
    return stack;
}

// Stack is full when top is equal to the last index
int Filled(reverse* stack)
{ return stack->top == stack->size - 1; }

// Stack is empty when top is equal to -1
int Empty(reverse* stack)
{ return stack->top == -1; }

// Function to add an item to stack.
// It increases top by 1
void push(reverse* stack, char item)
{
    if (Filled(stack))
        return;
    stack->stk[++stack->top] = item;
}

// Function to remove an item from stack.
// It decreases top by 1
char pop(reverse* stack)
{
    if (Empty(stack))
        return -1;
    return stack->stk[stack->top--];
}

// A stack based function to reverse a string
void Reverse(char str[])
{
// Create a stack of capacity
//equal to length of string
    int n = strlen(str) ;
    reverse* stack = BuildStack(n);
// Push all characters of string to stack
    int i;
    for (i = 0; i < n; i++)
        push(stack, str[i]);
// Pop all characters of string and
// put them back to str
    for (i = 0; i < n; i++)
        str[i] = pop(stack);
}

// Driver code
int main()
{
    char str[50];
    cout<<"Enter a string: ";
    cin.getline(str,50);
//    gets(str);  //这一行命令会导致第一条语句：cout<<"Enter a string: ";不能正常输出
    Reverse(str);
    cout << "Reversed string is " << str;
    return 0;
}
