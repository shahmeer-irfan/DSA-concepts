#include <iostream>
using namespace std;

class HashTable
{
    int size;   // Size of the hash table
    int *table; // Pointer to dynamically allocated array for the hash table

public:
    // Constructor to initialize the hash table with a given size
    HashTable(int s)
    {
        size = s;              // Set the size of the hash table
        table = new int[size]; // Dynamically allocate memory for the table
        for (int i = 0; i < size; i++)
        {
            table[i] = -1; // Initialize all slots to -1 (indicating empty slots)
        }
    }

    // Hash function to calculate index using modulo operation
    int hashFun(int k)
    {
        return k % size; // Returns the index by taking modulo of key with table size
    }

    // Function to insert a key into the hash table
    void insert(int k)
    {
        int index = hashFun(k); // Get the index for the key
        int i = 0;              // Variable for linear probing (collision handling)

        // Linear probing: Search for the next available slot
        while (table[(index + i) % size] != -1 && table[(index + i) % size] != -2)
        {
            i++; // Move to the next index
            if (i == size)
            {
                cout << "Table is full" << endl; // If all slots are filled, display a message
                return;                          // Stop insertion if the table is full
            }
        }

        // Insert the key into the first available slot found
        table[(index + i) % size] = k;
        cout << "Inserted at index : " << (index + i) % size << " key : " << k << endl;
    }

    // Function to search for a key in the hash table
    bool search(int k)
    {
        int index = hashFun(k); // Get the index for the key
        int i = 0;              // Variable for linear probing

        // Linear probing: Check each slot starting from the calculated index
        while (table[(index + i) % size] != -1)
        {
            if (table[(index + i) % size] == k)
            {
                cout << "Key: " << k << " found at index: " << (index + i) % size << endl;
                return true; // Return true if key is found
            }
            i++; // Move to the next index
            if (i == size)
            {
                break; // Break if we've checked all positions to prevent an infinite loop
            }
        }
        cout << "Key: " << k << " not found!" << endl; // If the key is not found, display a message
        return false;
    }

    // Function to remove a key from the hash table
    void remove(int k)
    {
        int index = hashFun(k); // Get the index for the key
        int i = 0;              // Variable for linear probing

        // Linear probing: Check each slot starting from the calculated index
        while (table[(index + i) % size] != -1)
        {
            if (table[(index + i) % size] == k)
            {
                table[(index + i) % size] = -2; // Mark the slot as deleted by assigning -2
                cout << "Key: " << k << " deleted from index: " << (index + i) % size << endl;
                return; // Return after successful deletion
            }
            i++; // Move to the next index
            if (i == size)
            {
                break; // Break if we've checked all positions to prevent an infinite loop
            }
        }
        cout << "Key: " << k << " not found to delete!" << endl; // If the key is not found, display a message
    }

    // Function to display the current state of the hash table
    void display()
    {
        // Iterate through all the indices of the table
        for (int i = 0; i < size; i++)
        {
            if (table[i] == -1)
            {
                cout << "Index: " << i << " is empty" << endl; // Display message for empty slot
            }
            else if (table[i] == -2)
            {
                cout << "Index: " << i << " is deleted" << endl; // Display message for deleted slot
            }
            else
            {
                cout << "Index: " << i << ": " << table[i] << endl; // Display the key at the index
            }
        }
    }
};

int main()
{
    HashTable ht(10); // Create a hash table of size 10

    // Insert some elements into the hash table
    ht.insert(15); // Insert key 15
    ht.insert(25); // Insert key 25
    ht.insert(35); // Insert key 35
    ht.insert(45); // Insert key 45

    // Display the current state of the hash table
    ht.display();

    // Search for an element in the hash table
    ht.search(25); // Search for key 25
    ht.search(50); // Search for key 50 (which does not exist)

    // Delete an element from the hash table
    ht.remove(25); // Delete key 25
    ht.remove(50); // Try to delete key 50 (which does not exist)

    // Display the hash table after deletion
    ht.display();

    return 0;
}
