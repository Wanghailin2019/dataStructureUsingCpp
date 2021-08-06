/********************************************************
    Filename:145_circular_queue_operation.cpp
    Author name: Timothy
    Time:2021/08/05
    Version:v1
    Description:
         Circular Queue Operation.
*********************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

//body of class
class CircularQueue
{
private : //declare data members
    int front,rear,size,*cq;
public:
    CircularQueue(int); //constructor
//method declarations
    void Enqueue(int);
    void Dequeue();
    void Print();
    bool isEmpty();
    bool isFull();
    void Clear();
    int getFront();
    int getRear();
};
//body of constructor
CircularQueue :: CircularQueue(int n)
{
    size= n;
    front=-1; //initialize front
    rear=-1; //initialize rear
    cq = new int[size]; //allocate memory for circular queue
}
//method will return the value of rear
int CircularQueue :: getRear()
{
    return rear;
}
//method will return the value of front
int CircularQueue :: getFront()
{
    return front;
}
//method will clear the elements of queue
void CircularQueue :: Clear()
{
    front=-1; //set front to -1
    rear=-1; //set rear to -1
}
//method will return true if circular queue is full
bool CircularQueue :: isFull()
{ //condition for circular queue is full
    if(front==0 && rear == size-1 || front ==
                                     rear+1)
        return true;
    else
        return false;
}
//method will return true if the circular queue is empty
bool CircularQueue :: isEmpty()
{
    if(front==-1) //condition for empty
        return true;
    else
        return false;
}
//method will print the elements of circular queue
void CircularQueue :: Print()
{
    int i;
    if (isEmpty()) //check for empty queue
        printf("\n CIRCULAR QUEUE IS EMPTY!");
    else
    if (front > rear) //print the elements when front > rear
        {
            for(i = front; i <= size-1; i++)
                cout<<cq[i]<<setw(5);
            for(i = 0; i <= rear; i++)
                cout<<cq[i]<<setw(5);  //setw()指定空格大小函数
        }
    else //print the elements from front to rear
        for(i = front; i <= rear; i++)
            cout<<cq[i]<<setw(5);
}
//method will insert an element into circular queue
void CircularQueue :: Enqueue(int n)
{
    if (isFull()) //condition for overflow
    {
        printf("\n Overflow! ");
        return;
    }
    if (rear == -1) /* Insert first element */
    {
        front = 0;
        rear = 0;
    }
    else
    if (rear == size-1) //if rear is at last then assign it to first
        rear = 0;
    else
        rear++; //increment the value of rear
//assign the number into circular queue
    cq[rear]= n ;
}
//method to delete the elements from queue
void CircularQueue :: Dequeue()
{
    int ch;
    if (isEmpty()) //condition for underflow
    {
        printf("\nUnderflow!");
        return ;
    }
//print the element which is to be delete
    cout<<endl<<cq[front]<<" deleted from circular queue";
    if(front ==rear) //condition for queue having single element
        {
            Clear();
        }
    else if ( front == size-1)
        front = 0;
    else
        front++;
}
//driver program
int main()
{
    int opt,n;
    char ch;
    cout<<endl<<"Enter the size of circular queue: ";
    cin>>n; //ask user about the size of circular queue
    CircularQueue obj(n); //declare an object
///infinite loop to control the program
    while(1)
    {
        cout<<endl<<"******* M E N U ********";
        cout<<endl<<"e. ENQUEUE\nd. Dequeue\nm. isEmpty\nu. isFull\nc.Clear\nf. Get Front\nr. Get Rear\np. Print\nq. Quit";
        cout<<endl<<"Enter Choice : ";
        cin>>ch;
///condition for enqueue()
        if(ch=='e' || ch=='E')
        {
            cout<<endl<<"Enter the number to insert: ";
            cin>>opt;
            obj.Enqueue(opt);
        }
        else //condition for dequeue()
        if(ch=='d' || ch=='D')
        {
            obj.Dequeue();
        }
        else //condition for call to isEmpty()
        if(ch=='m' || ch=='M')
        {
            if(obj.isEmpty())
                cout<<endl<<"Circular Queue is EMPTY";
            else
                cout<<endl<<"Circular Queue is not empty" ;
        }
        else //condition to call isFull()
        if(ch=='u' || ch=='U')
        {
            if(obj.isFull())
                cout<<endl<<"Circular Queue is FULL";
            else
                cout<<endl<<"Circular Queue is not Full" ;
        }
        else //condition to call clear()
        if(ch=='c' || ch=='C')
            obj.Clear();
        else
        if(ch=='f' || ch=='F') //condition to call getFront()
            cout<<endl<<"Front = "<<obj.getFront();
        else
        if(ch=='r' || ch=='R') //condition to call getRear()
            cout<<endl<<"Rear = "<<obj.getRear();
        else //condition to call Print()
        if(ch=='p' || ch=='P')
            obj.Print();
        else //condition to terminate the program
        if(ch=='q' || ch=='Q')
            exit(0);
        else
            cout<<endl<<"Invalid Choice";
    }
    return 0;
}