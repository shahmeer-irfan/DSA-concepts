#include <iostream>
using namespace std;
#include <queue>;

void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) //excluding leaf nodes cuz they are already heap.
        heapify(arr, n, i);

    // One by one extract elements from the heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to the end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Utility function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    cout<<"By using priority queue"<<endl;
    //this is max heap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(3);
    pq.push(2);
    pq.push(7);
    pq.push(5);

    cout<<"element at Top: "<< pq.top()<<endl;
    pq.pop();
    cout << "element at Top: " << pq.top() << endl;
    //pq.size();

    //how to implement minHeap
    priority_queue<int, vector<int>, greater<int> > minHeap;
    return 0;
}
