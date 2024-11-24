#include <iostream>
#include <stdexcept>

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Queue class
class Queue {
private:
    Node* head; // Pointer to the front of the queue
    Node* tail; // Pointer to the end of the queue
    int count;  // Number of elements in the queue

public:
    // Constructor
    Queue() : head(nullptr), tail(nullptr), count(0) {}

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return count == 0;
    }

    // Add an element to the end of the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    // Remove and return the front element of the queue
    int dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        int value = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;

        if (isEmpty()) {
            tail = nullptr; // Reset tail if the queue is empty
        }
        return value;
    }

    // Get the front element without removing it
    int peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return head->data;
    }

    // Get the size of the queue
    int size() const {
        return count;
    }
};

// Main function for testing
int main() {
    Queue queue;

    // Test operations
    try {
        std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << "\n";

        std::cout << "Enqueuing elements: 10, 20, 30\n";
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);

        std::cout << "Queue size: " << queue.size() << "\n";
        std::cout << "Front element (peek): " << queue.peek() << "\n";

        std::cout << "Dequeuing element: " << queue.dequeue() << "\n";
        std::cout << "Queue size after dequeue: " << queue.size() << "\n";

        std::cout << "Dequeuing all elements...\n";
        while (!queue.isEmpty()) {
            std::cout << "Dequeued: " << queue.dequeue() << "\n";
        }

        std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
