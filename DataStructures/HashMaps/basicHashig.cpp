#include <iostream>
using namespace std;

//No Collisons Scenario

class HashTable {
private:
    int size;
    int* keys;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int s) : size(s) {
        keys = new int[size];
        for (int i = 0; i < size; ++i) {
            keys[i] = -1; // Initialize all keys to -1 (empty)
        }
    }

    ~HashTable() {
        delete[] keys;
    }

    void insert(int key) {
        int index = hashFunction(key);
        keys[index] = key; // Insert the key
    }

    void deleteItem(int key)
    {
        int index=hashFunction(key);
        keys[index]=-1;
    }

    bool search(int key) {
        int index = hashFunction(key);
        return keys[index] == key; // Return true if the key matches
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << i << ": ";
            if (keys[i] != -1)
                cout << keys[i]; // Display the key only
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(5);
    ht.insert(0);
    ht.insert(1);
    ht.insert(2);
    ht.insert(3);
    ht.insert(4);
    
    ht.deleteItem(2);
    ht.display();

    int key = 2;
    if (ht.search(key))
        cout << "Key " << key << " found in the hash table." << endl;
    else
        cout << "Key " << key << " not found in the hash table." << endl;

    return 0;
}
