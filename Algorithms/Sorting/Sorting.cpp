//23k-0832
#include <iostream>

using namespace std;

class Sorting
{
    int *array;
    int num;

public:
    Sorting(const int num, const int *arr) : num(num)
    {
        array = new int[num];
        for (int i = 0; i < num; i++)
        {
            array[i] = arr[i];
        }
    }

    Sorting(const Sorting &other) : num(other.num)
    {
        array = new int[num];
        for (int i = 0; i < num; i++)
        {
            array[i] = other.array[i];
        }
    }

    void bubbleSort()
    {
        for (int i = 0; i < num; i++)
        {
            bool flag = false;
            for (int j = 0; j < num - i - 1; j++)
            {
                if (array[j] > array[j + 1])
                {
                    swap(array[j], array[j + 1]);
                    flag = true;
                }
            }
            if (!flag) //exiting if array is already sorted
            {
                break;
            }
        }
    }

    void insertionSort()
    {
        for (int i = 1; i < num; i++)  //starting from second element cuz array is already sorted
        {
            int j = i - 1;  //one element before target element
            int key = array[i];  
            while (j >= 0 && array[j] > key)
            {
                array[j + 1] = array[j]; //shifting element
                j--; //moving backward
            }
            array[j + 1] = key;
        }
    }

    void selectionSort()
    {
        for (int i = 0; i < num - 1; i++)
        {
            int minIndex = i; //minimum index
            for (int j = i + 1; j < num; j++)
            {
                if (array[minIndex] > array[j])
                {
                    minIndex = j;
                }
            }
            if (minIndex != i)
            {
                swap(array[minIndex], array[i]);
            }
        }
    }

    void shellSort()
    {
        for (int gap = num / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < num; i++)
            {
                int key = array[i];
                int j = i;
                while (j >= gap && array[j - gap] > key)
                {
                    array[j] = array[j - gap];
                    j -= gap;
                }
                array[j] = key;
            }
        }
    }

    void combSort()
    {
        int gap = num;
        const float shrink = 1.3;
        bool swapped = true;

        while (gap > 1 || swapped)
        {
            gap = gap / shrink;
            if (gap < 1)
            {
                gap = 1;
            }

            swapped = false;

            for (int i = 0; i < num - gap; i++)
            {
                if (array[i] > array[i + gap])
                {
                    swap(array[i], array[i + gap]);
                    swapped = true;
                }
            }
        }
    }

    int linearSearch(int target)
    {
        for (int i = 0; i < num; i++)
        {
            if (array[i] == target)
            {
                return i;
            }
        }
        return -1;
    }

    int binarySearch(int target)
    {
        int low = 0;
        int high = num - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (array[mid] == target)
            {
                return mid;
            }
            else if (array[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return -1;
    }

    int interpolationSearch(int key)
    {
        int low = 0;
        int high = num - 1;

        while (low <= high && key >= array[low] && key <= array[high])
        {
            if (low == high)
            {
                if (array[low] == key)
                    return low;
                return -1;
            }

            int pos = low + ((key - array[low]) * (high - low)) / (array[high] - array[low]);

            if (array[pos] == key)
            {
                return pos;
            }
            else if (array[pos] < key)
            {
                low = pos + 1;
            }
            else
            {
                high = pos - 1;
            }
        }

        return -1;
    }

    ~Sorting()
    {
        delete[] array;
    }

    void printArray() const
    {
        for (int i = 0; i < num; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void resetArray(const int *arr)
    {
        for (int i = 0; i < num; i++)
        {
            array[i] = arr[i];
        }
    }
};

int main()
{
    const int size = 10;
    int array[size] = {2, 5, 4, 56, 5, 3, 21, 2, 3, 8};

    Sorting Array01(size, array);

    cout << "Original array: ";
    Array01.printArray();

    Array01.bubbleSort();
    cout << "Sorted array (Bubble Sort): ";
    Array01.printArray();

    Array01.resetArray(array);
    Array01.insertionSort();
    cout << "Sorted array (Insertion Sort): ";
    Array01.printArray();

    Array01.resetArray(array);
    Array01.selectionSort();
    cout << "Sorted array (Selection Sort): ";
    Array01.printArray();

    Array01.resetArray(array);
    Array01.shellSort();
    cout << "Sorted array (Shell Sort): ";
    Array01.printArray();

    Array01.resetArray(array);
    Array01.combSort();
    cout << "Sorted array (Comb Sort): ";
    Array01.printArray();

    // Search Test
    int target = 56;
    int linearIndex = Array01.linearSearch(target);
    cout << "Linear Search for " << target << ": " << (linearIndex != -1 ? "Found at index " + to_string(linearIndex) : "Not found") << endl;

    Array01.bubbleSort(); // Binary and Interpolation search require sorted array
    int binaryIndex = Array01.binarySearch(target);
    cout << "Binary Search for " << target << ": " << (binaryIndex != -1 ? "Found at index " + to_string(binaryIndex) : "Not found") << endl;

    int interpolationIndex = Array01.interpolationSearch(target);
    cout << "Interpolation Search for " << target << ": " << (interpolationIndex != -1 ? "Found at index " + to_string(interpolationIndex) : "Not found") << endl;

    return 0;
}
