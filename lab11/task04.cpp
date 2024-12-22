
//23k-0832
#include <iostream>
#include <vector>
using namespace std;

class BankingHashTable
{
private:
    vector<int> table;
    int capacity; // Hash table size

    // Primary hash function
    int primaryHash(int accountID)
    {
        return accountID % capacity;
    }

    // Secondary hash function
    int secondaryHash(int accountID)
    {
        return 7 - (accountID % 7);
    }

    // Find a slot using double hashing
    int findSlot(int accountID, bool forInsert = false)
    {
        int primary = primaryHash(accountID);
        int secondary = secondaryHash(accountID);
        int index = primary;

        for (int i = 0; i < capacity; i++)
        {
            index = (primary + i * secondary) % capacity;

            if (forInsert && (table[index] == -1 || table[index] == -2))
            {
                return index; // Slot is free or marked as deleted
            }
            if (!forInsert && table[index] == accountID)
            {
                return index; // Account ID found
            }
            if (!forInsert && table[index] == -1)
            {
                break; // ID not found and reached empty slot
            }
        }
        return -1; // No valid slot found
    }

public:
    BankingHashTable(int size) : capacity(size)
    {
        table = vector<int>(capacity, -1); // Initialize with -1 (empty slots)
    }

    // Insert account ID into the hash table
    void insert(int accountID)
    {
        int slot = findSlot(accountID, true);
        if (slot != -1)
        {
            table[slot] = accountID;
            cout << "Inserted account ID " << accountID << " at index " << slot << endl;
        }
        else
        {
            cout << "Failed to insert account ID " << accountID << ": Table full" << endl;
        }
    }

    // Search for an account ID in the hash table
    void search(int accountID)
    {
        int slot = findSlot(accountID);
        if (slot != -1)
        {
            cout << "Found account ID " << accountID << " at index " << slot << endl;
        }
        else
        {
            cout << "Account ID " << accountID << " not found." << endl;
        }
    }

    // Delete an account ID from the hash table
    void remove(int accountID)
    {
        int slot = findSlot(accountID);
        if (slot != -1)
        {
            table[slot] = -2; // Mark the slot as deleted
            cout << "Deleted account ID " << accountID << " from index " << slot << endl;
        }
        else
        {
            cout << "Account ID " << accountID << " not found, deletion failed." << endl;
        }
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
            else if (table[i] == -2)
            {
                cout << "[" << i << "]: Deleted" << endl;
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
    // Step a: Create hash table with size 11
    BankingHashTable bankTable(11);

    // Insert account numbers: 101, 111, 121, 131, 141, 151
    bankTable.insert(101);
    bankTable.insert(111);
    bankTable.insert(121);
    bankTable.insert(131);
    bankTable.insert(141);
    bankTable.insert(151);

    cout << endl
         << "After inserting account numbers 101-151:" << endl;
    bankTable.display();

    cout << endl
         << "Search operations:" << endl;
    bankTable.search(111);
    bankTable.search(141);
    bankTable.search(161);

    bankTable.remove(111);
    bankTable.remove(131);

    cout << endl
         << "After deleting account numbers 111 and 131:" << endl;
    bankTable.display();

    bankTable.insert(161);
    bankTable.insert(171);

    cout << endl
         << "After inserting account numbers 161 and 171:" << endl;
    bankTable.display();

    return 0;
}
