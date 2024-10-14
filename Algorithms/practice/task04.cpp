//23k-0832
#include <iostream>
using namespace std;

int recursiveArraySum(int **arr, int sizes[], int dim, int index = 0)
{
    if (dim == 0)
    {
        return 0; // Base case for zero dimensions
    }
    if (index >= sizes[0])
    {
        return recursiveArraySum(arr + 1, sizes + 1, dim - 1); // Move to the next dimension
    }
    return arr[0][index] + recursiveArraySum(arr, sizes, dim, index + 1); // Sum current dimension
}

int main()
{
    int *arr[3];
    int sizes[] = {3, 2, 5}; // Sizes of each dimension

    arr[0] = new int[3]{1, 6, 3};
    arr[1] = new int[2]{4, 5};
    arr[2] = new int[5]{6, 7, 8, 9, 2};

    int total = recursiveArraySum(arr, sizes, 3);
    cout << "Sum of all elements: " << total << endl;

    for (int i = 0; i < 3; i++)
    {
        delete[] arr[i]; // Free allocated memory
    }

    return 0;
}
