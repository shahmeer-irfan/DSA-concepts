//23k-0832
#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse
using namespace std;

int getMax(const vector<int> &arr)
{
    int max = arr[0];
    for (int num : arr)
    {
        if (num > max)
        {
            max = num;
        }
    }
    return max;
}

// Function to perform counting sort based on the digit represented by exp
void countingSort(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> output(n); // Output array
    int count[10] = {0};   // Count array for digits 0-9

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // Update count[i] so that count[i] contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[]
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// Main radix sort function
void radixSort(vector<int> &arr)
{
    int max = getMax(arr); // Get maximum value
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, exp); // Sort by the current digit
    }
}

// Function to print the array
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {36, 987, 654, 2, 20, 99, 456, 957, 555, 420, 66, 3};

    // Sort in ascending order
    radixSort(arr);
    cout << "Sorted in Ascending Order: ";
    printArray(arr);

    // Sort in descending order by reversing the sorted array
    reverse(arr.begin(), arr.end());
    cout << "Sorted in Descending Order: ";
    printArray(arr);

    return 0;
}
