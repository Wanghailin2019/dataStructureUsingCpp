/********************************************************
    Filename:203_student_data_using_linked_list.cpp
    Author name: Timothy
    Time:2021/08/06
    Version:v1
    Description:
          Program for Student Data Using Linked List.
*********************************************************/

# include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<string>
using namespace std;
struct student
{
    string fname,lname;
    int yob,mob,dob;
    char sex;
    int age;
    float mark;
    struct student *next;
};
struct student start,*last,*New;
//method declarations
void insert(struct student *);
void create(struct student *);
void display(struct student *);
void average(struct student *);
void maximum(struct student *);
void search(struct student *);
void printmale(struct student *);

//driver program
int main()
{ /* FUNCTION MAIN */
    struct student *node;
    create(node); //create the link list
    int opt;
//infinite loop
    while(1)
    {//display the menu
        cout<<endl<<"1. Add Friend \n2. Display friends\n 8. Print Average age of friends\n 9. Print Male Friends\n 0. Exit\n";
        cout<<endl<<"Enter choice";
        cin>>opt; //read the choice
//call to the corresponding methods according to the users input
        if(opt==1)
            insert(node);
        else
        if(opt==2)
            display(node);
        else
        if(opt==8)
            average(node);
        else
        if(opt==9)
            printmale(node);
        else
        if(opt==0)
            exit(0);
        else
            cout<<endl<<"Invalid choice";
    }
    return 0;
}
//create method read the data from file and stores it into link list
void create(struct student *node)
{
    int n;
    char ch;
    string name;
    start.next = NULL; /* Empty list */
    node = &start; /* Point to the start of the list */
    while(1)
    {
//allocate memory for a node of list
        node->next = (struct student* ) malloc(sizeof(struct student));
        node = node->next; //shift the node to next node
        cout<<endl<<"Enter the first name";
        cin>>name;
        node->fname = name;
        cout<<endl<<"Enter the last name";
        cin>>name;
        node->lname = name;
//        fflush(stdin);
        cout<<endl<<"Enter the year of birth";
        cin>>n;
        node->yob=n;
        cout<<endl<<"Enter the month of birth";
        cin>>n;
        node->mob=n;
        cout<<endl<<"Enter the day of birth";
        cin>>n;
        node->dob=n;
        cout<<endl<<"Enter the sex[m/f]";
        cin>>ch;
        node->sex=ch;
        node->next = NULL;//assign NULL to end
        cout<<endl<<"Do you want to create more nodes[y/n]";
        cin>>ch;
        if(ch=='n'|| ch=='N')
            break;
    }
}
//insert a new node
void insert(struct student *node)
{
    string name;
    int n;
    char ch;
    node = start.next;
    last = &start;
    while(node)//loop will continue till end
    {
        node = node->next;
        last= last->next;
    }
    if(node == NULL)
    {
//allocate new memory for new node
        New = (struct student* ) malloc(sizeof(struct student));
//logic for insertion
        New->next = node ;
        last->next = New;
//ask data to user
        cout<<endl<<"Enter the first name";
        cin>>name;
        New->fname=name;
        cout<<endl<<"Enter the last name";
        cin>>name;
        New->lname=name;
        cout<<endl<<"Enter the year of birth";
        cin>>n;
        New->yob=n;
        cout<<endl<<"Enter the month of birth";
        cin>>n;
        New->mob=n;
        cout<<endl<<"Enter the day of birth";
        cin>>n;
        New->dob=n;
        cout<<endl<<"Enter the sex[m/f]";
        cin>>ch;
        New->sex=ch;
    }
}
//method to diaply the data
void display(struct student *node)
{
    node = start.next;//points to first node oflist
    while (node)//loop will continue till end of list
    {//print the data
        cout<<endl<<node->fname<<"\t"<<node->lname<<"\t"<<node->yob<<"\t"<<node->mob<<"\t"<<node->dob<<"\t"<<node->sex;
        node = node->next;//shift the pointer to next node
    }
}
void printmale(struct student *node)
{
    node = start.next;//points to first node oflist
    while (node)//loop will continue till end of list
    {
        if(node->sex=='m'||node->sex=='M')
//print the data
        cout<<endl<<node->fname<<"\t"<<node->lname<<"\t"<<node->yob<<"\t"<<node->mob<<"\t"<<node->dob<<"\t"<<node->sex;
        node = node->next;//shift the pointer to next node
    }
}
void average(struct student *node)
{
    float avg;
    int sum=0,c=0;
    node = start.next;//points to first node oflist
    while (node)//loop will continue till end of list
    {
        c++;
        sum = sum+ node->age;
        node = node->next;//shift the pointer to next node
    }
    avg=(float)sum/c;
}
void youngest(struct student *node)
{
    int minyear,minmon,minday,c=0;
    string name1,name2;
    node = start.next;//points to first node oflist
    minyear=node->yob;
    minmon=node->mob;
    minday=node->dob;
    while (node)//loop will continue till end of list
    {
        if(minyear > node->yob)
        {
            name1=node->fname;
            name2=node->lname;
        }
        if(minyear == node->yob && minmon > node->mob)
        {
            name1=node->fname;
            name2=node->lname;
        }
        if(minyear == node->yob && minmon == node->mob &&
           minday >node->dob)
        {
            name1=node->fname;
            name2=node->lname;
        }
        node = node->next;//shift the pointer to next node
    }
    cout<<endl<<"Youngest Friend is "<<name1<<"\t"<<name2;
}
void oldest(struct student *node)
{
    int minyear,minmon,minday,c=0;
    string name1,name2;
    node = start.next;//points to first node of list
    minyear=node->yob;
    minmon=node->mob;
    minday=node->dob;
    while (node)//loop will continue till end of list
    {
        if(minyear < node->yob)
        {
            name1=node->fname;
            name2=node->lname;
        }
        if(minyear == node->yob && minmon < node->mob)
        {
            name1=node->fname;
            name2=node->lname;
        }
        if(minyear == node->yob && minmon == node->mob &&
           minday < node->dob)
        {
            name1=node->fname;
            name2=node->lname;
        }
        node = node->next;//shift the pointer to next node
    }
    cout<<endl<<"Oldest Friend is "<<name1<<"\t"<<name2;
}
