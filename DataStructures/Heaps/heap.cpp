#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

// A class for Max Heap
class MaxHeap
{
    int *arr;     // Pointer to the array to store the heap
    int maxSize;  // Maximum size of the heap
    int heapSize; // Current number of elements in the heap

public:
    // Constructor: Initializes the max heap with a given size
    MaxHeap(int totSize)
    {
        heapSize = 0;
        maxSize = totSize;
        arr = new int[totSize];
    }

    // Returns the index of the parent of element at index i
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    // Returns the index of the left child of element at index i
    int lChild(int i)
    {
        return (2 * i + 1);
    }

    // Returns the index of the right child of element at index i
    int rChild(int i)
    {
        return (2 * i + 2);
    }

    // Restores the Max Heap property for the subtree rooted at index i
    void MaxHeapify(int i)
    {
        int l = lChild(i);
        int r = rChild(i);
        int largest = i;

        if (l < heapSize && arr[l] > arr[largest])
            largest = l;

        if (r < heapSize && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            MaxHeapify(largest);
        }
    }

    // Inserts a new key 'x' into the Max Heap
    void insertKey(int x)
    {
        if (heapSize == maxSize)
        {
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }

        // Insert the new key at the end
        heapSize++;
        int i = heapSize - 1;
        arr[i] = x;

        // Restore the Max Heap property
        while (i != 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Removes and returns the maximum element (root) of the Max Heap
    void removeMax()
    {
        if (heapSize <= 0)
        {
            cout << "heap is empty" << endl;
        }

        arr[0] = arr[heapSize - 1];
        heapSize--;

        // Restore the Max Heap property
        MaxHeapify(0);
    }

    // Returns the maximum element in the Max Heap
    int getMax()
    {
        return heapSize > 0 ? arr[0] : -1;
    }

    int curSize()
    {
        return heapSize;
    }

    void print()
    {
        for(int i=0;i<heapSize;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    // Create a MaxHeap with a maximum size of 15
    MaxHeap h(15);

    // Insert elements into the MaxHeap
    h.insertKey(3);
    h.insertKey(10);
    h.insertKey(12);
    h.insertKey(8);
    h.insertKey(2);
    h.insertKey(15);

    // cout << "The current size of the heap is " << h.curSize() << "\n";
    // cout << "The current maximum element is " << h.getMax() << "\n";
    h.print();
    h.removeMax();

    cout << "The current maximum element is " << h.getMax() << "\n";
    h.print();

    
    return 0;
}
