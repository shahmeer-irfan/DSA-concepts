//Afaq Ahmed Soomro
//23k-0901
#include <iostream>

using namespace std;
const int TABLE_SIZE = 128;

class HashTable {
private:
    int* table;
    int current_size;
    int capacity;

    int hashFunction(int key) {
        return key % capacity;
    }

    void rehash() {
        int old_capacity = capacity;
        capacity *= 2;
        int* old_table = table;
        table = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            table[i] = -1; // Assuming -1 indicates an empty slot
        }
        current_size = 0;

        for (int i = 0; i < old_capacity; i++) {
            if (old_table[i] != -1) {
                insert(old_table[i]);
            }
        }
        delete[] old_table;
    }

public:
    HashTable() {
        capacity = TABLE_SIZE;
        table = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            table[i] = -1;
        }
        current_size = 0;
    }

    ~HashTable() {
        delete[] table;
    }

    void insert(int key) {
        if (current_size >= capacity / 2) {
            rehash();
        }
        int index = hashFunction(key);
        while (table[index] != -1) {
            index = (index + 1) % capacity;
        }
        table[index] = key;
        current_size++;
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            if (table[i] != -1) {
                cout << i << " --> " << table[i] << endl;
            } else {
                cout << i << endl;
            }
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(1);
    ht.insert(2);
    ht.insert(3);
    ht.display();
    return 0;
}