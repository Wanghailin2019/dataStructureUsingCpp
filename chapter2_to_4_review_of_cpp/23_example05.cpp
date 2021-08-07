/********************************************************
    Filename:23_example05.cpp
    Author name: Timothy
    Time:2021/08/03
    Version:v1
    Description:
          Find the length of a string.
*********************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char x[20];
    int i,len=0;
    cout<<"\n Enter a string";
    gets(x);
    for(i=0;x[i]!='\0';i++)
        len++;
    cout<<"\n THE LENGTH OF "<<x<<" IS "<<len;
    //直接使用strlen()函数就可以获得string的长度，注意需要包含头文件#include<cstring>
    cout<<"\n the length of "<<x<<" is "<<strlen(x);
    return 0;
}