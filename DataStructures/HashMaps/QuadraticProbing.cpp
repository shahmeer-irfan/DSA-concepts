#include <iostream>
using namespace std;

class HashTableQuadraticProbing
{
private:
    int size;
    int *keys;

    // Hash function to calculate index using modulo operation
    int hashFunction(int key)
    {
        return key % size;
    }

public:
    // Constructor to initialize the hash table with a given size
    HashTableQuadraticProbing(int s) : size(s)
    {
        keys = new int[size];
        for (int i = 0; i < size; ++i)
        {
            keys[i] = -1; // Initialize all slots as empty (-1)
        }
    }

    // Destructor to free the dynamically allocated memory
    ~HashTableQuadraticProbing()
    {
        delete[] keys;
    }

    // Function to insert a key into the hash table
    void insert(int key)
    {
        int index = hashFunction(key);
        int i = 0;

        // Quadratic probing to handle collisions
        while (keys[(index + (i * i)) % size] != -1)
        {
            i++; // Increase the probing step
            if (i == size)
            {
                cout << "Table is full. Cannot insert the key: " << key << endl;
                return; // Table is full, exit
            }
        }

        index = (index + (i * i)) % size;
        keys[index] = key;
        cout << "Inserted key " << key << " at index " << index << endl;
    }

    // Function to search for a key in the hash table
    bool search(int key)
    {
        int index = hashFunction(key);
        int i = 0;

        // Quadratic probing to find the key
        while (keys[(index + (i * i)) % size] != -1)
        {
            if (keys[(index + (i * i)) % size] == key)
            {
                return true; // Key found
            }
            i++;
            if (i == size)
            {
                break; // Avoid infinite loop if the key is not present
            }
        }

        return false; // Key not found
    }

    // Function to delete a key from the hash table
    void deleteItem(int key)
    {
        int index = hashFunction(key);
        int i = 0;

        // Quadratic probing to find and delete the key
        while (keys[(index + (i * i)) % size] != -1)
        {
            if (keys[(index + (i * i)) % size] == key)
            {
                keys[(index + (i * i)) % size] = -1; // Mark the slot as empty (-1)
                cout << "Deleted key " << key << " from index " << (index + (i * i)) % size << endl;
                return;
            }
            i++;
            if (i == size)
            {
                break; // Avoid infinite loop if key is not found
            }
        }

        cout << "Key " << key << " not found to delete!" << endl; // Key not found
    }

    // Function to display the hash table
    void display()
    {
        cout << "Hash Table: " << endl;
        for (int i = 0; i < size; ++i)
        {
            cout << i << ": ";
            if (keys[i] != -1)
            {
                cout << "{" << keys[i] << "}";
            }
            else
            {
                cout << "{}";
            }
            cout << endl;
        }
    }
};

int main()
{
    HashTableQuadraticProbing ht(5); // Create a hash table of size 5

    ht.insert(1);
    ht.insert(2);
    ht.insert(6); // This will collide with 1 (due to the hash function)
    ht.insert(7); // This will collide with 2 (due to the hash function)

    ht.display(); // Display the current state of the hash table

    cout << "After deleting 6" << endl;
    ht.deleteItem(6); // Delete key 6
    ht.display();     // Display after deletion

    int key = 6;
    cout << "Key " << key << " found: " << (ht.search(key) ? "Yes" : "No") << endl; // Search for key 6

    return 0;
}
