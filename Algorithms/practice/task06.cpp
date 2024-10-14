//23k-0832
#include <iostream>
using namespace std;

struct Car
{
    int id;
    Car *next;
    Car(int val) : id(val), next(nullptr) {}
};

class CircularQueue
{
public:
    Car *head;

    CircularQueue() : head(nullptr) {}

    void enqueue(int id)
    {
        Car *newCar = new Car(id);
        if (!head)
        {
            head = newCar;
            newCar->next = head; // Circular link
        }
        else
        {
            Car *temp = head;
            while (temp->next != head)
            {
            temp = temp->next;
            }
            temp->next = newCar;
            newCar->next = head; // Maintain circularity
        }
    }

    void dequeue()
    {
        if (!head)
            return;

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Car *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        Car *toDelete = head;
        head = head->next;
        temp->next = head; // Update the last car's next to the new head
        delete toDelete;
    }

    void display()
    {
        if (!head)
            return;
        Car *temp = head;
        do
        {
            cout << "Car ID: " << temp->id << endl;
            temp = temp->next;
        } while (temp != head);
    }
};

int main()
{
    CircularQueue cq;
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);

    cout << "Cars in the circular queue:" << endl;
    cq.display();

    cq.dequeue(); // Remove the first car
    cout << "After removing a car:" << endl;
    cq.display();

    return 0;
}
