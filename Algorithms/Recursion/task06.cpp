//23k-0832 
#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci number " << n << " is: " << fibonacci(n) << endl;
    return 0;
}
