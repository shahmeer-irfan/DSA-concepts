//23k-0832
#include <iostream>
using namespace std;

int factorialNonTail(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * factorialNonTail(n - 1);
}

int factorialTailHelper(int n, int pile)
{
    if (n == 0 || n == 1)
    {

        return pile;
    }
    return factorialTailHelper(n - 1, n * pile);
}

int factorialTail(int n)
{
    return factorialTailHelper(n, 1);
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Factorial (Non-Tail Recursion) of " << num << " is: " << factorialNonTail(num) << endl;
    cout << "Factorial (Tail Recursion) of " << num << " is: " << factorialTail(num) << endl;

    return 0;
}
