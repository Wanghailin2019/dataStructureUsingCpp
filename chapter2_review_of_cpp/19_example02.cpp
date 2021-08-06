/********************************************************
    filename:19_example02.cpp
    Author name: Timothy
    Time:2021/08/03
    version:v1
    description:
         input a 3 x 3 matrix and find out the sum of lower triangular elements.
*********************************************************/
#include<iostream>
using namespace std;

int main()
{
    int mat[3][3],i,j,sum=0;
    /* Input the array*/
    for(i=0 ; i<3 ; i++)
        for(j=0 ; j<3 ; j++)
        {
            cout<<"\nEnter a number ";
            cin>>mat[i][j];
        }
    /* LOGIC TO SUM THE LOWER TRIANGULAR ELEMENTS */
    for(i=0;i<3;i++)
        for(j=0;j<=i;j++)
        {
            sum=sum+mat[i][j];
        }
    /* PRINT THE ARRAY */
    cout<<"\nTHE ENTERED MATRIX IS\n";
    for(i=0 ; i<3 ; i++)
    {
        for(j=0 ; j<3 ; j++)
        {
            cout<<" "<<mat[i][j];
        }
        cout<<"\n";
    }
    cout<<"\nSum of the lower triangular matrix is "<<sum;

    return 0;
}
