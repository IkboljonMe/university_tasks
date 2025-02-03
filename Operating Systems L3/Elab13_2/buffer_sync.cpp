#include <iostream>
#include <pthread.h>
#include <fcntl.h>
#include <semaphore.h>
#include <queue>
#include <unistd.h>

#define BUFFER_SIZE 9

using namespace std;

queue<char> buffer;
sem_t *buffer_mutex, *empty_slots, *filled_slots, *can_read;

void* producerA(void* arg) {
    while (true) {
        sem_wait(empty_slots);
        sem_wait(buffer_mutex);

        buffer.push('A');
        cout << "Producer A added: A" << endl; cout.flush();
        
        if (buffer.size() > 3)
            sem_post(can_read);
        
        sem_post(buffer_mutex);
        sem_post(filled_slots);
        sleep(1);
    }
}

void* producerB(void* arg) {
    while (true) {
        sem_wait(empty_slots);
        sem_wait(buffer_mutex);

        buffer.push('B');
        cout << "Producer B added: B" << endl; cout.flush();
        
        if (buffer.size() > 3)
            sem_post(can_read);
        
        sem_post(buffer_mutex);
        sem_post(filled_slots);
        sleep(1);
    }
}

void* consumerA(void* arg) {
    while (true) {
        sem_wait(can_read);
        sem_wait(filled_slots);
        sem_wait(buffer_mutex);

        if (!buffer.empty() && buffer.front() == 'A') {
            buffer.pop();
            cout << "Consumer A removed: A" << endl; cout.flush();
        }
        
        sem_post(buffer_mutex);
        sem_post(empty_slots);
        sleep(2);
    }
}

void* consumerB(void* arg) {
    while (true) {
        sem_wait(can_read);
        sem_wait(filled_slots);
        sem_wait(buffer_mutex);

        if (!buffer.empty() && buffer.front() == 'B') {
            buffer.pop();
            cout << "Consumer B removed: B" << endl; cout.flush();
        }
        
        sem_post(buffer_mutex);
        sem_post(empty_slots);
        sleep(2);
    }
}

int main() {
    cout << "Main started" << endl; cout.flush();

    pthread_t pA, pB, cA, cB;

    buffer_mutex = sem_open("/buffer_mutex", O_CREAT, 0644, 1);
    empty_slots = sem_open("/empty_slots", O_CREAT, 0644, BUFFER_SIZE);
    filled_slots = sem_open("/filled_slots", O_CREAT, 0644, 0);
    can_read = sem_open("/can_read", O_CREAT, 0644, 0);

    // 🔴 **Pre-fill buffer to unblock consumers**
    sem_wait(buffer_mutex);
    for (int i = 0; i < 4; i++) {
        buffer.push((i % 2 == 0) ? 'A' : 'B');
        sem_post(filled_slots);
    }
    cout << "Pre-filled buffer with 4 elements\n"; cout.flush();
    sem_post(can_read);
    sem_post(buffer_mutex);

    pthread_create(&pA, NULL, producerA, NULL);
    pthread_create(&pB, NULL, producerB, NULL);
    pthread_create(&cA, NULL, consumerA, NULL);
    pthread_create(&cB, NULL, consumerB, NULL);

    pthread_join(pA, NULL);
    pthread_join(pB, NULL);
    pthread_join(cA, NULL);
    pthread_join(cB, NULL);

    sem_close(buffer_mutex);
    sem_close(empty_slots);
    sem_close(filled_slots);
    sem_close(can_read);

    sem_unlink("/buffer_mutex");
    sem_unlink("/empty_slots");
    sem_unlink("/filled_slots");
    sem_unlink("/can_read");

    return 0;
}
