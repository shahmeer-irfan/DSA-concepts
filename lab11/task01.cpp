// 23k-0832
#include <iostream>
#include <list>
using namespace std;

struct Book
{
    int id;
    string title;
    string author;
};

class LibraryCatalog
{
private:
    static const int SIZE = 10;
    list<Book> table[SIZE];

    int hashFunction(int bookID)
    {
        return (bookID / 10) % SIZE;
    }

public:
    void insertBook(const Book &book)
    {
        int index = hashFunction(book.id);
        table[index].push_back(book);
        cout << "Inserted book ID " << book.id << " (" << book.title << ") at index " << index << endl;
    }

    bool searchBook(int bookID)
    {
        int index = hashFunction(bookID);
        for (const auto &book : table[index])
        {
            if (book.id == bookID)
            {
                cout << "Found book ID " << book.id << " (" << book.title << ") by " << book.author << endl;
                return true;
            }
        }
        cout << "Book ID " << bookID << " not found." << endl;
        return false;
    }

    void deleteBook(int bookID)
    {
        int index = hashFunction(bookID);
        for (auto it = table[index].begin(); it != table[index].end(); ++it)
        {
            if (it->id == bookID)
            {
                cout << "Deleted book ID " << it->id << " (" << it->title << ") by " << it->author << endl;
                table[index].erase(it);
                return;
            }
        }
        cout << "Book ID " << bookID << " not found. Cannot delete." << endl;
    }

    void display()
    {
        cout << "Library Catalog Hash Table:" << endl;
        for (int i = 0; i < SIZE; ++i)
        {
            cout << "Index " << i << ": ";
            for (const auto &book : table[i])
            {
                cout << "[" << book.id << " - " << book.title << " - " << book.author << "] ";
            }
            cout << endl;
        }
    }
};

int main()
{
    LibraryCatalog catalog;

    catalog.insertBook({101, "Book1A", "AuthorA"});
    catalog.insertBook({102, "BooK3A", "AuthorA"});
    catalog.insertBook({103, "Book3A", "AuthorA"});
    catalog.insertBook({201, "Book1B", "AuthorB"});
    catalog.insertBook({202, "Book2B", "AuthorB"});
    catalog.insertBook({301, "Book1C", "AuthorC"});
    catalog.insertBook({302, "Book2C", "AuthorC"});
    catalog.insertBook({303, "Book3C", "AuthorC"});
    catalog.insertBook({304, "Book4C", "AuthorC"});

    catalog.display();

    cout << endl
         << "Searching for books:" << endl;
    catalog.searchBook(102);
    catalog.searchBook(301);
    catalog.searchBook(999);

    cout << endl
         << "Deleting books:" << endl;
    catalog.deleteBook(102);
    catalog.deleteBook(301);

    cout << endl
         << "After Deletions:" << endl;
    catalog.display();

    return 0;
}
