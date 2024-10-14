//23k-0382
#include <iostream>
using namespace std;

void insertElement(int arr[], int j, int last)
{

    if (j < 0 || arr[j] <= last)
    {
        arr[j + 1] = last;
        return;
    }

    arr[j + 1] = arr[j];

    insertElement(arr, j - 1, last);
}

void insertInSortedOrder(int arr[], int n)
{
    if (n <= 1)
    {
        return; // Base case: array of size 1 is already sorted
    }

    // Recursively sort the first n-1 elements
    insertInSortedOrder(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    // Call a recursive function to shift elements and place the last element in the correct position
    insertElement(arr, j, last);
}

int main()
{
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertInSortedOrder(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
