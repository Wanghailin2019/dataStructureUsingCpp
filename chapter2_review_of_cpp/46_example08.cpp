/********************************************************
    Filename:46_example08.cpp
    Author name: Timothy
    Time:2021/08/04
    Version:v1
    Description:
          to demonstrate the difference between the structure and Union.

          The only difference between the structure and
        union is based upon the memory management i.e/ the structure data type
        will occupies the sum of total number of bytes occupied by its individual
        data members where as in case of union it will occupy the highest number
        of byte occupied by its data members
*********************************************************/
#include<iostream>
using namespace std;

struct stdd
{
    char name[20],add[30];
    int roll,total;
    float avg;
};

union std1
{
    char name[20],add[30];
    int roll,total;
    float avg;
};

int main()
{
    struct stdd s;
    union std1 s1;
    cout<<"\nThe no.of bytes occupied by the structure is "<<sizeof(struct stdd);
    cout<<"\nThe no.of bytes occupied by the union is"<<sizeof(union std1);

    return 0;
}