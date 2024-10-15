//23k-0832
#include <iostream>
#include <string>
using namespace std;

class Runners
{
    string name;
    int time;

public:
    // Parameterized constructor
    Runners(string n, int t)
    {
        name = n;
        time = t;
    }

    // Default constructor
    Runners()
    {
        name = "";
        time = 0;
    }

    // Function to merge two subarrays
    void merge(Runners runners[], int start, int mid, int end)
    {
        int len1 = mid - start + 1; // first half
        int len2 = end - mid;       // second half

        Runners *first = new Runners[len1];
        Runners *second = new Runners[len2];

        // copying first half
        int k = start;
        for (int i = 0; i < len1; i++)
        {
            first[i] = runners[k++];
        }

        // copying second half
        k = mid + 1;
        for (int j = 0; j < len2; j++)
        {
            second[j] = runners[k++];
        }

        // merging both arrays
        int i = 0, j = 0;
        k = start;
        while (i < len1 && j < len2)
        {
            if (first[i].time < second[j].time)
                runners[k++] = first[i++];
            else
                runners[k++] = second[j++];
        }

        while (i < len1)
        { // copying remaining elements of left array
            runners[k++] = first[i++];
        }

        while (j < len2)
        { // copying remaining elements of right array
            runners[k++] = second[j++];
        }

        delete[] first;
        delete[] second;
    }

    // Function to perform merge sort
    void mergeSort(Runners runners[], int start, int end)
    {
        if (start >= end)
        {
            return;
        }

        int mid = start + (end - start) / 2;
        mergeSort(runners, start, mid); // mid included (different from quicksort)
        mergeSort(runners, mid + 1, end);
        merge(runners, start, mid, end);
    }

    // Function to display a runner's details
    void display() const
    {
        cout << "Runner Name: " << name << ", Finish Time: " << time << " seconds" << endl;
    }

    // Setter for Runners
    void setRunner(string n, int t)
    {
        name = n;
        time = t;
    }
};

int main()
{
    const int totalRunners = 10;
    Runners runner[totalRunners];

    // Input participants' names and finish times
    cout << "Enter the names and finish times (in seconds) of " << totalRunners << " participants:" << endl;
    for (int i = 0; i < totalRunners; i++)
    {
        string name;
        int time;
        cout << "Participant " << (i + 1) << " Name: ";
        cin >> name;
        cout << "Finish Time (in seconds): ";
        cin >> time;
        runner[i].setRunner(name, time);
    }

    // Create an object to use the merge sort function
    Runners sorter;
    sorter.mergeSort(runner, 0, totalRunners - 1);

    // Display the top 5 fastest runners
    cout << "\nTop 5 fastest runners:" << endl;
    for (int i = 0; i < 5; i++)
    {
        runner[i].display();
    }

    return 0;
}
