#include <iostream>

using namespace std;

int partion(int arr[], int low, int high)
{
    int pivot = arr[low]; //first element as pivot
    int i = low + 1;  //starting from second element
    int j = high; //last element

    while (i <= j) //loop until i and j cross each other
    {
        while (arr[i] <= pivot) //if element is less than pivot then move to next element
        {
            i++;
        }

        while (arr[j] > pivot) //if element is greater than pivot then move to previous element
        {
            j--;
        }

        if (i < j) //if i and j have not crossed each other then swap the elements
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]); //swap pivot element with element at j to make pivot at right positioon
    return j; //return pivot position
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int pivot = partion(arr, low, high); 
    quickSort(arr, low, pivot - 1);  // sorting left part before pivot element
    quickSort(arr, pivot + 1, high); // sorting right part after pivot+1
}

int main()
{
    int arr[] = {5, 2, 3, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }


    return 0;
}