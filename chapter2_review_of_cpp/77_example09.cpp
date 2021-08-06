/********************************************************
    Filename:77_example09.cpp
    Author name: Timothy
    Time:2021/08/04
    Version:v1
    Description:
        about class and static
*********************************************************/

#include<iostream>
using namespace std;

class demo
{
private:
    static int x;
public:
    void change();
    void display();
};
void demo :: display()
{
    cout<<x;
}
void demo :: change()
{
    x++;
}
int demo :: x=5;
int main()
{
    demo obj,obj1,obj2;
    obj.display();
    obj1.display();
    obj2.display();
    obj.change();
    obj.display();
    obj1.display();
    obj2.display();

    return 0;
}
