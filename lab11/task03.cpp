// 23k-0832
#include <iostream>
#include <vector>
using namespace std;

class AcademicPortal
{
private:
    vector<int> table; // Hash table to store student IDs
    int capacity;      // Current size of the hash table
    int size;          // Current number of student IDs in the table
    float loadFactor;  // Threshold for resizing

    // Hash function for placing IDs
    int hashFunction(int studentID)
    {
        return studentID % capacity;
    }

    // Function to resize the table when load factor exceeds threshold
    void resizeTable()
    {
        int oldCapacity = capacity;
        capacity *= 2; // Double the table size
        vector<int> oldTable = table;

        // Reinitialize the table with the new capacity
        table = vector<int>(capacity, -1);
        size = 0; // Reset size to reinsert all elements

        // Rehash all existing IDs into the new table
        for (int i = 0; i < oldCapacity; i++)
        {
            if (oldTable[i] != -1)
            {
                insert(oldTable[i]);
            }
        }
        cout << "Resized hash table to capacity " << capacity << endl;
    }

    // Find the next available slot (linear probing)
    int findSlot(int studentID)
    {
        int index = hashFunction(studentID);
        while (table[index] != -1)
        {
            index = (index + 1) % capacity; // Linear probing
        }
        return index;
    }

public:
    AcademicPortal(int initialCapacity, float loadFactorThreshold)
        : capacity(initialCapacity), size(0), loadFactor(loadFactorThreshold)
    {
        table = vector<int>(capacity, -1);
    }

    // Insert a student ID into the hash table
    void insert(int studentID)
    {
        if ((float)(size + 1) / capacity > loadFactor)
        {
            resizeTable();
        }

        int index = findSlot(studentID);
        table[index] = studentID;
        size++;
        cout << "Inserted student ID " << studentID << " at index " << index << endl;
    }

    // Search for a student ID in the hash table
    void search(int studentID)
    {
        int index = hashFunction(studentID);
        int start = index;

        while (table[index] != -1)
        {
            if (table[index] == studentID)
            {
                cout << "Found student ID " << studentID << " at index " << index << endl;
                return;
            }
            index = (index + 1) % capacity;
            if (index == start)
                break; // Full cycle completed
        }
        cout << "Student ID " << studentID << " not found." << endl;
    }

    // Display the hash table
    void display()
    {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < capacity; i++)
        {
            if (table[i] == -1)
            {
                cout << "[" << i << "]: Empty" << endl;
            }
            else
            {
                cout << "[" << i << "]: " << table[i] << endl;
            }
        }
    }
};

int main()
{
    // Step a: Create a hash table with initial size of 7 and load factor threshold 0.75
    AcademicPortal portal(7, 0.75);

    // Insert student IDs: 12, 22, 32, 42, 52, 62
    portal.insert(12);
    portal.insert(22);
    portal.insert(32);
    portal.insert(42);
    portal.insert(52);
    portal.insert(62);

    cout << endl
         << "After inserting student IDs 12-62:" << endl;
    portal.display();

    // Step b: Search for student IDs: 22, 42, 72
    cout << endl
         << "Search operations:" << endl;
    portal.search(22);
    portal.search(42);
    portal.search(72);

    // Step c: Insert additional IDs: 72, 82 to exceed the load factor threshold
    portal.insert(72);
    portal.insert(82);

    cout << endl
         << "After inserting IDs 72 and 82 (resize triggered):" << endl;
    portal.display();

    return 0;
}
