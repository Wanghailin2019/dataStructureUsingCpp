/********************************************************
    filename:23_example04.cpp
    Author name: Timothy
    Time:2021/08/03
    version:v1
    description:
          input a string and count how many vowels are in it.
*********************************************************/

#include<iostream>
using namespace std;
int main()
{
    char x[20];
    int i,count=0;
    cout<<"\n Enter a string";
    gets(x);
    cout<<"\n The entered string is"<<x;
    for(i=0; x[i]!='\0';i++)
        if(toupper(x[i])=='A' || toupper(x[i])=='E'
           || toupper(x[i])=='I' || toupper(x[i])=='O' ||
           toupper(x[i])=='U')
            count++;
    cout<<"\n The string "<<x<< " having "<<count<<" numbers of vowels";
    return 0;
}
