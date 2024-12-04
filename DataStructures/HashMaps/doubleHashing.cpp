#include <iostream>
using namespace std;

class HashTableDoubleHashing {
private:
    int size;
    int* keys;

    int hash1(int key) {
        return key % size;
    }

    int hash2(int key) {
        return 1 + (key % (size - 1));
    }

public:
    HashTableDoubleHashing(int s) : size(s) {
        keys = new int[size];
        for (int i = 0; i < size; ++i) {
            keys[i] = -1;
        }
    }

    ~HashTableDoubleHashing() {
        delete[] keys;
    }

    void insert(int key) {
        int index = hash1(key);
        int step = hash2(key);
        while (keys[index] != -1) {
            index = (index + step) % size;
        }
        keys[index] = key;
    }

    bool search(int key) {
        int index = hash1(key);
        int step = hash2(key);
        while (keys[index] != -1) {
            if (keys[index] == key)
                return true;
            index = (index + step) % size;
        }
        return false; // Key not found
    }

    void deleteItem(int key)
    {
        int index=hash1(key);
        int step=hash2(key);
        while(keys[index]!=-1)
        {
            if(keys[index]==key)
            {
                keys[index]=-1;
                return;
            }
            index=(index+step)%size;
        }
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << i << ": ";
            if (keys[i] != -1)
                cout << "{" << keys[i] << "}";
            cout << endl;
        }
    }
};

int main() {
    HashTableDoubleHashing ht(5);
    ht.insert(1);
    ht.insert(2);
    ht.insert(6);
    ht.insert(7);
    ht.display();

    cout<<"After deleting 6"<<endl;
    ht.deleteItem(6);
    ht.display();

    int key = 2;
    cout << "Key " << key << (ht.search(key) ? " found" : " not found") << endl;

    return 0;
}
