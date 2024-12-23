#include <iostream>
#include <vector>
using namespace std;

class HashTableChaining
{
private:
    struct Node
    {
        int key;
        Node *next;
        Node(int k) : key(k), next(nullptr) {}
    };

    int size;
    vector<vector<int>> keys; // Vector of vectors to represent chains

    int hashFunction(int key)
    {
        return key % size;
    }

public:
    HashTableChaining(int s) : size(s), keys(s) {}

    void insert(int key)
    {
        int index = hashFunction(key);
        for (int existingKey : keys[index])
        {
            if (existingKey == key)
            {
                return; // Key already exists
            }
        }
        keys[index].push_back(key);
    }

    bool search(int key)
    {
        int index = hashFunction(key);
        for (int existingKey : keys[index])
        {
            if (existingKey == key)
            {
                return true;
            }
        }
        return false; // Key not found
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key);
        auto &chain = keys[index];

        for (auto it = chain.begin(); it != chain.end(); ++it)
        {
            if (*it == key)
            {
                chain.erase(it);
                cout << "Key " << key << " deleted." << endl;
                return;
            }
        }

        cout << "Key " << key << " not found." << endl;
    }

    void display()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << i << ": ";
            for (int key : keys[i])
            {
                cout << "{" << key << "} -> ";
            }
            cout << "NULL";
            cout << endl;
        }
    }
};

int main()
{
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
