// 23k-0832
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Student
{
    string name;
    int score;
    Student *next;

    Student(string n, int s) : name(n), score(s), next(nullptr) {}
};

class StudentLinkedList
{
private:
    Student *head;

public:
    StudentLinkedList() : head(nullptr) {}

    void insert(string name, int score)
    {
        Student *newStudent = new Student(name, score);
        newStudent->next = head;
        head = newStudent;
    }

    Student *getHead()
    {
        return head;
    }

    void clear()
    {
        while (head != nullptr)
        {
            Student *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int getMaxScore(StudentLinkedList &students)
{
    int maxScore = 0;
    Student *current = students.getHead();
    while (current != nullptr)
    {
        if (current->score > maxScore)
        {
            maxScore = current->score;
        }
        current = current->next;
    }
    return maxScore;
}

void countingSort(StudentLinkedList &students, int place)
{
    const int range = 101;               // Scores between 0 and 100
    Student *buckets[range] = {nullptr}; // Initialize bucket pointers

    Student *current = students.getHead();
    while (current != nullptr)
    {
        int bucketIndex = (current->score / place) % 10;
        Student *newStudent = new Student(current->name, current->score);
        newStudent->next = buckets[bucketIndex];
        buckets[bucketIndex] = newStudent;
        current = current->next;
    }

    students.clear(); // Clear original list

    // Reconstruct the linked list from the buckets
    for (int i = 0; i < range; i++)
    {
        Student *bucketHead = buckets[i];
        while (bucketHead != nullptr)
        {
            students.insert(bucketHead->name, bucketHead->score);
            Student *temp = bucketHead;
            bucketHead = bucketHead->next;
            delete temp; // Free memory after inserting
        }
    }
}

void radixSort(StudentLinkedList &students)
{
    int maxScore = getMaxScore(students);

    for (int place = 1; maxScore / place > 0; place *= 10)
    {
        countingSort(students, place);
    }
}

void printStudents(StudentLinkedList &students)
{
    Student *current = students.getHead();
    while (current != nullptr)
    {
        cout << current->name << ": " << current->score << endl;
        current = current->next;
    }
}

int main()
{
    StudentLinkedList students;

    // Sample student records
    students.insert("Zara", 85);
    students.insert("Sara", 45);
    students.insert("Amir", 92);
    students.insert("David", 65);
    students.insert("Hadi", 75);
    students.insert("Ayan", 95);
    students.insert("Sameer", 60);
    students.insert("Ali", 50);
    students.insert("Muzammil", 80);
    students.insert("Suji", 30);

    cout << "Student records before sorting:" << endl;
    printStudents(students);

    radixSort(students);

    cout << "\nStudent records after sorting:" << endl;
    printStudents(students);

    students.clear(); // Clean up
    return 0;
}
