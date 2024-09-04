#include <iostream>
#include <vector>
//vectors can dynamicallly grow and shrink.
using namespace std;

int main ()
{
    vector<int> v1 = {1,2,3,4,5}; //vector of integers.

    cout<<v1[1]<<endl;
  //  v1.front(); //returns the first element of the vector.
    v1.back(); //returns the last element of the vector.
    v1.size(); //returns the size of the vector.
    v1.push_back(2); //pushes the element at the end of the vector.

    v1.insert(v1.begin(), 3); //inserts the element at the beginning of the vector.

    v1.erase(v1.begin()); //erases the element at the beginning of the vector.
    //we dont need to pass any arguments. 
    v1.pop_back(); //pops the element from the end of the vector.
 
    vector<int> :: iterator it; //pointer to an vector array/
    for(it=v1.begin();it!=v1.end(); it++)
    {
        cout<<*it<<endl;
    }

    return 0;
}


//capacity of vector doesnt decrease automatically. 
//so we use shrink_to_fit() it shrink the vector to fit the number of elements in it.
