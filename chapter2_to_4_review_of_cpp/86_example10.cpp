/********************************************************
    Filename:86_example10.cpp
    Author name: Timothy
    Time:2021/08/04
    Version:v1
    Description:
        this pointer
        This pointer is a special type of pointer which is used to know the address
of the current object that means it always stores the address of current
object. We can also handle the members of a class as
            this->member_name;
*********************************************************/

#include<iostream>
using namespace std;

class even
{
private:
    int n;
public:
    void input();
    void check();
};
void even :: input()
{
    cout<<"Enter a number: ";
    cin>>this->n;
}
void even :: check()
{
    cout<<"THE ADDRESS OF OBJECT IS "<<this;
    if(this->n %2==0)
        cout<<endl<<this->n<<" IS EVEN ";
    else
    cout<<endl<<this->n<<" IS NOT EVEN ";
}
int main()
{
    even obj;
    obj.input();
    obj.check();
    return 0;
}