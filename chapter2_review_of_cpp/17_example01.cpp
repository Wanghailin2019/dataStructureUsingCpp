/********************************************************
    filename:17_example01.cpp
    Author name: Timothy
    Time:2021/08/03
    version:v1
    description:
        Input 10 Elements Into an Array and Display Them.
*********************************************************/

#include<iostream>
using namespace std;

int main()
{
    int x[10],i;
    cout<<"\nEnter 10 elements into the array";
    for(i=0 ; i<10; i++)
        cin>>x[i];
    cout<<"\n THE ENTERED ARRAY ELEMENTS ARE :";
    for(i=0 ; i<10; i++)
        cout<<"x[i] = "<<x[i]<<"\n";
    return 0;
}