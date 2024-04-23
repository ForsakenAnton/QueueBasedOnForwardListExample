#include <iostream>
using namespace std;

template <typename T>
struct Node 
{
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr)
    {
    }
};

// Реалізована на на базі односпрямованого списку
template <typename T>
class Queue 
{
private:
    Node<T>* front; // Перший елемент черги
    Node<T>* rear;  // Останній елемент черги

public:
    Queue() : front(nullptr), rear(nullptr) 
    { }

    ~Queue() 
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }

    void enqueue(const T& value) 
    {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) 
        {
            front = rear = newNode;
        }
        else 
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cerr << "Queue is empty. Cannot dequeue." << std::endl;

            return;
        }

        Node<T>* temp = front;
        front = front->next;

        delete temp;

        if (front == nullptr)
        {
            rear = nullptr;
        }
    }

    T& peekFront() const 
    {
        if (isEmpty()) 
        {
            cerr << "Queue is empty." << endl;

            // Повертаємо посилання, щоб уникнути невизначеної поведінки,
            // але у реальних сценаріях вона повинна оброблятися належним чином
            static T dummy;

            return dummy; // (!)
        }
        return front->data;
    }

    void display() const 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Node<T>* current = front;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    Queue<int> myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    cout << "Front of the queue: " << myQueue.peekFront() << endl;

    cout << "Queue elements: ";
    myQueue.display();

    myQueue.dequeue();
    cout << "After dequeue:" << endl;
    cout << "Front of the queue: " << myQueue.peekFront() << endl;
    cout << "Queue elements: ";
    myQueue.display();

    return 0;
}