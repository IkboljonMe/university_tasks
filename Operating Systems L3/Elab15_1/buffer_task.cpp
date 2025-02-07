#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

#define BUFFER_SIZE 7
int buffer[BUFFER_SIZE];  // FIFO Buffer
int front = 0, rear = 0;  // Buffer pointers

std::mutex buffer_mutex;            // Mutex to protect buffer access
std::condition_variable full_slots; // Condition variable for full slots in the buffer
std::condition_variable empty_slots; // Condition variable for empty slots in the buffer

// Producer A: Produces even numbers
void producerA() {
    int num = 2;
    while (true) {
        std::unique_lock<std::mutex> lock(buffer_mutex);
        empty_slots.wait(lock, []{ return (rear + 1) % BUFFER_SIZE != front; });  // Wait for an empty slot
        buffer[rear] = num;
        rear = (rear + 1) % BUFFER_SIZE;
        std::cout << "Producer A produced: " << num << std::endl;
        full_slots.notify_one();  // Signal that there is a new item
        num += 2;
    }
}

// Producer B: Produces odd numbers
void producerB() {
    int num = 1;
    while (true) {
        std::unique_lock<std::mutex> lock(buffer_mutex);
        empty_slots.wait(lock, []{ return (rear + 1) % BUFFER_SIZE != front; });  // Wait for an empty slot
        buffer[rear] = num;
        rear = (rear + 1) % BUFFER_SIZE;
        std::cout << "Producer B produced: " << num << std::endl;
        full_slots.notify_one();  // Signal that there is a new item
        num += 2;
    }
}

// Consumer A: Can consume any number
void consumerA() {
    while (true) {
        std::unique_lock<std::mutex> lock(buffer_mutex);
        full_slots.wait(lock, []{ return front != rear; });  // Wait for a full slot
        int num = buffer[front];
        front = (front + 1) % BUFFER_SIZE;
        std::cout << "Consumer A consumed: " << num << std::endl;
        empty_slots.notify_one();  // Signal that a slot is now empty
    }
}

// Consumer B: Can consume only even numbers
void consumerB() {
    while (true) {
        std::unique_lock<std::mutex> lock(buffer_mutex);
        full_slots.wait(lock, []{ return front != rear; });  // Wait for a full slot
        int num = buffer[front];
        if (num % 2 != 0) {  // If it's an odd number, skip it
            continue;
        }
        front = (front + 1) % BUFFER_SIZE;
        std::cout << "Consumer B consumed even number: " << num << std::endl;
        empty_slots.notify_one();  // Signal that a slot is now empty
    }
}

// Consumer C: Can consume only odd numbers
void consumerC() {
    while (true) {
        std::unique_lock<std::mutex> lock(buffer_mutex);
        full_slots.wait(lock, []{ return front != rear; });  // Wait for a full slot
        int num = buffer[front];
        if (num % 2 == 0) {  // If it's an even number, skip it
            continue;
        }
        front = (front + 1) % BUFFER_SIZE;
        std::cout << "Consumer C consumed odd number: " << num << std::endl;
        empty_slots.notify_one();  // Signal that a slot is now empty
    }
}

int main() {
    std::thread pA(producerA);
    std::thread pB(producerB);
    std::thread cA(consumerA);
    std::thread cB(consumerB);
    std::thread cC(consumerC);

    pA.join();
    pB.join();
    cA.join();
    cB.join();
    cC.join();

    return 0;
}
