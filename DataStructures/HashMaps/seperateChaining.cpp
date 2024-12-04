#include <iostream>
using namespace std;

class HashTableChaining {
private:
    struct Node {
        int key;
        Node* next;
        Node(int k) : key(k), next(nullptr) {}
    };

    int size;
    Node** keys;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTableChaining(int s) : size(s) {
        keys = new Node*[size];
        for (int i = 0; i < size; ++i) {
            keys[i] = nullptr;
        }
    }

    ~HashTableChaining() {
        for (int i = 0; i < size; ++i) {
            Node* entry = keys[i];
            while (entry != nullptr) {
                Node* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] keys;
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        if (keys[index] == nullptr) {
            keys[index] = newNode;
        } else {
            Node* entry = keys[index];
            while (entry->next != nullptr) {
                if (entry->key == key) {
                    delete newNode;
                    return;
                }
                entry = entry->next;
            }
            if (entry->key == key) {
                delete newNode;
            } else {
                entry->next = newNode;
            }
        }
    }

    bool search(int key) {
        int index = hashFunction(key);
        Node* entry = keys[index];
        while (entry != nullptr) {
            if (entry->key == key) {
                return true;
            }
            entry = entry->next;
        }
        return false; // Key not found
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        Node* entry = keys[index];
        Node* prev = nullptr;

        while (entry != nullptr && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            cout << "Key " << key << " not found." << endl;
            return;
        }

        if (prev == nullptr) {
            keys[index] = entry->next;
        } else {
            prev->next = entry->next;
        }

        delete entry;
        cout << "Key " << key << " deleted." << endl;
    }
    void display() {
        for (int i = 0; i < size; ++i) {
            cout << i << ": ";
            Node* entry = keys[i];
            while (entry != nullptr) {
                cout << "{" << entry->key << "} -> ";
                entry = entry->next;
            }
            cout << "NULL";
            cout << endl;
        }
    }
};

int main() {
    HashTableChaining ht(5);
    ht.insert(1);
    ht.insert(2);
    ht.insert(3);
    ht.insert(8);

    ht.display();

    ht.deleteItem(3);

    ht.display();

    int key = 3;
    cout << "Key " << key << (ht.search(key) ? " found" : " not found") << endl;

    return 0;
}