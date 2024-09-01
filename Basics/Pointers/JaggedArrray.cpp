#include <iostream>

using namespace std;

/*Jagged array is similar to an array but the difference is that its an array of arrays in which the member
arrays can be in different sizes.*/


int main()
{
   int size;

   cout<<"Enter Number of Sizes"<<endl;
   cin>>size;

   int jagged[size];

    cout<<"Enter Sizes of Arrays:"<<endl;
   for(int i=0;i<size;i++)
   {
    cin>>jagged[i];
   }

   int **array = new int*[size];

   for(int i=0;i<size;i++)
   {
    array[i] = new int[jagged[i]];
   }

    cout<<"Enter Elements of an Array"<<endl;
   for(int i=0;i<size;i++)
   {
    for(int j=0;j<jagged[i];j++)
    {
        cin>>array[i][j];
    }
   }

   cout<<"Array:"<<endl;
   for (int i = 0; i < size; i++)
   {
       for (int j = 0; j < jagged[i]; j++)
       {
           cout<<array[i][j]<<"";
       }

    cout<<endl;
   }

    return 0;
}