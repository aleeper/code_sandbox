#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

void Read(int reader_id, queue<int>* q, std::mutex* mutex) {
    while (true) {
        std::scoped_lock lock(*mutex);
        if (!q->empty()) {
            int value = q->front();
            cout << "Reading " << value << " from reader " << reader_id << endl;
            q->pop();
            if (value > 5) break;
        }
    }
}

void Write(queue<int>* q, std::mutex* mutex) {
    int sequence = 0;
    while (sequence < 10) {
        usleep(5e5);
        sequence++;
        cout << "Writing " << sequence << endl;
        std::scoped_lock lock(*mutex);
        q->push(sequence);
    }
}

int main(int argc, char** argv) {
    std::queue<int> q;
    std::mutex mutex;

    std::thread reader1(Read, 1, &q, &mutex);
    std::thread reader2(Read, 2, &q, &mutex);
    std::thread writer(Write, &q, &mutex);

    writer.join();
    reader1.join();
    reader2.join();
}
