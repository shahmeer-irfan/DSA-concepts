#include <iostream>

using namespace std;

int main()
{
    int rows;
    int columns;

    cout<<"Enter number of rows"<<endl;
    cin>>rows;
    cout<<"Enter number of columns"<<endl;
    cin>>columns;

    int **array = new int*[rows]; //created an array of type pointer.
    
    for(int i=0;i<rows;i++)
    {
        array[i] = new int[columns]; //allocated columns for each pointer from array of pointers.
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout<<"Enter element at position "<<i<<","<<j<<endl;
            cin>>array[i][j]; //taking input from user.    
        }
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout<<array[i][j]<<" "; 
        }
        cout<<endl;
    }

    for(int i=0;i<rows;i++)
    {
        delete[] array[i]; //deleting columns for each pointer from array of pointers.
    }

    delete[] array; //deleting array of pointers.

//we cant't directly delete array of pointers, because it will cause memory leak.
    return 0;
}