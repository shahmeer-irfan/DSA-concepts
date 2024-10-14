//23k-0832
#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int left, int right, int target)
{
    if (left > right)
    {
        return -1; // Target not found
    }

    int mid = right + left / 2;

    if (arr[mid] == target)
    {
        return mid; // Target found at mid
    }
    else if (arr[mid] > target)
    {
        return binarySearchRecursive(arr, left, mid - 1, target); // Search left half
    }
    else
    {
        return binarySearchRecursive(arr, mid + 1, right, target); // Search right half
    }
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the target number: ";
    cin >> target;

    int result = binarySearchRecursive(arr, 0, size - 1, target);

    if (result != -1)
    {
        cout << "Target found at index: " << result << endl;
    }
    else
    {
        cout << "Target not found." << endl;
    }

    return 0;
}
