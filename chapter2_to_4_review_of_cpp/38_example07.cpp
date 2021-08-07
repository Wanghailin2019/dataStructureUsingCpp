/********************************************************
    Filename:38_example07.cpp
    Author name: Timothy
    Time:2021/08/04
    Version:v1
    Description:
          C++关于指针的一些操作测试
          1. &x,取变量的地址
          2. *p,取指针p指的地址的值
*********************************************************/


#include<iostream>
using namespace std;

int main()
{
    int *p,x;
    p=&x;
    cin>>x;
    cout<<*p<<endl;
    cout<<x<<endl;
    cout<<p<<endl; //输出指针所指的地址


    return 0;
}
