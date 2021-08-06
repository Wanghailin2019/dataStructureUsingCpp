/********************************************************
    Filename:36_example06.cpp
    Author name: Timothy
    Time:2021/08/04
    Version:v1
    Description:
          Show Difference between STATIC and AUTO.
    ps:auto的作用域只在函数内部，static可以函数间仍有效
*********************************************************/

#include<stdio.h>
void main()
{
    void change();
    change();
    change();
    change();
}
Void change()
{
    auto int x=0;
    printf("n X= %d",x);
    x++;
}
//OUTPUT
//X=0
//X=0
//X=0

#include<stdio.h>
void main()
{
    void change();
    change();
    change();
    change();
}
Void change()
{
    static int x;
    printf("\n X= %d",x);
    x++;
}
//OUTPUT
//X=0
//X=1
//X=2