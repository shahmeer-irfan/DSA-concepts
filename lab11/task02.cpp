// 23k-0832
#include <iostream>
#include <vector>
using namespace std;

class FitnessClub
{
private:
    static const int SIZE = 7;
    vector<int> table;      // Fixed-size hash table
    vector<bool> isDeleted; // Marks deleted slots for reuse

    int hashFunction(int memberID)
    {
        return memberID % SIZE;
    }

    int findSlot(int memberID)
    {
        int index = hashFunction(memberID);
        int originalIndex = index;

        // Linear probing to find next available slot
        while (table[index] != -1 && table[index] != memberID && !isDeleted[index])
        {
            index = (index + 1) % SIZE;
            if (index == originalIndex) // Full table
                return -1;
        }
        return index;
    }

public:
    FitnessClub() : table(SIZE, -1), isDeleted(SIZE, false) {}

    void insert(int memberID)
    {
        int index = findSlot(memberID);
        if (index == -1)
        {
            cout << "Hash table is full. Cannot insert member ID " << memberID << endl;
            return;
        }
        table[index] = memberID;
        isDeleted[index] = false;
        cout << "Inserted member ID " << memberID << " at index " << index << endl;
    }

    void search(int memberID)
    {
        int index = hashFunction(memberID);
        int originalIndex = index;

        while (table[index] != -1)
        {
            if (table[index] == memberID)
            {
                cout << "Found member ID " << memberID << " at index " << index << endl;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == originalIndex)
                break;
        }
        cout << "Member ID " << memberID << " not found." << endl;
    }

    void remove(int memberID)
    {
        int index = hashFunction(memberID);
        int originalIndex = index;

        while (table[index] != -1)
        {
            if (table[index] == memberID)
            {
                cout << "Deleted member ID " << memberID << " from index " << index << endl;
                table[index] = -1;
                isDeleted[index] = true; // Mark the slot as deleted
                return;
            }
            index = (index + 1) % SIZE;
            if (index == originalIndex)
                break;
        }
        cout << "Member ID " << memberID << " not found. Cannot delete." << endl;
    }

    void display()
    {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < SIZE; i++)
        {
            if (table[i] == -1 && !isDeleted[i])
                cout << "[" << i << "]: Empty" << endl;
            else if (table[i] == -1 && isDeleted[i])
                cout << "[" << i << "]: Deleted" << endl;
            else
                cout << "[" << i << "]: " << table[i] << endl;
        }
    }
};

int main()
{
    FitnessClub club;

    club.insert(10);
    club.insert(20);
    club.insert(30);
    club.insert(40);
    club.insert(50);
    club.insert(60);

    cout << endl
         << "After inserting member IDs 10-60:" << endl;
    club.display();

    cout << endl
         << "Search operations:" << endl;
    club.search(30);
    club.search(50);
    club.search(70);


    cout << endl
         << "Delete operations:" << endl;
    club.remove(20);
    club.remove(40);

    cout << endl
         << "After deletions:" << endl;
    club.display();

    // Insert additional member IDs 70, 80
    cout << endl
         << "Insert additional member IDs 70 and 80:" << endl;
    club.insert(70);
    club.insert(80);

    cout << endl
         << "Final hash table:" << endl;
    club.display();

    return 0;
}
