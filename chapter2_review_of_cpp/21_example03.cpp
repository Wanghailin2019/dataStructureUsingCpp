/********************************************************
    filename:21_example03.cpp
    Author name: Timothy
    Time:2021/08/03
    version:v1
    description:
         input a string and display it.
*********************************************************/
#include <iostream>
using namespace std;

int main(){
    char x[20];
    cout<<"Enter a string";
    gets(x);
    cout<<"\n THE ENTERED STRING IS "<<x;
    return 0;
}