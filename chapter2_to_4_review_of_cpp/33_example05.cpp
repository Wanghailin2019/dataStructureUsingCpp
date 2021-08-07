/********************************************************
    Filename:33_example05.cpp
    Author name: Timothy
    Time:2021/08/04
    Version:v1
    Description:
          Show Difference Between Call by Value and Call by Reference.
*********************************************************/

#include<iostream>
using namespace std;

void change(int a,int b) {
    a = a + 5;
    b = b + 5;
    cout << "\n X = " << a << " and Y = " << b;
}

void change(int *a, int *b)
{
    *a=*a+5;
    *b=*b+6;
    cout<<"\n X = "<<*a<<" and Y = "<<*b;
}

int main()
{
    int x=5,y=6;

    cout<<"\n X= "<<x<<" and Y = "<<y;
    change(x,y);
    cout<<"\n X= "<<x<<" and Y = "<<y;
    change(&x,&y);  //函数重载
    cout<<"\n X= "<<x<<" and Y = "<<y;

    return 0;
}
