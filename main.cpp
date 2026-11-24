#include <iostream>

struct Queue {
    static constexpr int capacity = 6;

    int data[capacity]{};
    int head = 0;
    int tail = 0;
    int count = 0;
};

bool enqueue(Queue& q, int value) {
    if (q.count == Queue::capacity) {
        return false;
    }

    q.data[q.tail] = value;
    q.tail = (q.tail + 1) % Queue::capacity;
    ++q.count;

    return true;
}

bool dequeue(Queue& q, int& value) {
    if (q.count == 0) {
        return false;
    }

    value = q.data[q.head];
    q.head = (q.head + 1) % Queue::capacity;
    --q.count;

    return true;
}

void task_10_1_4() {
    Queue q;
    int value = 0;

    std::cout << std::boolalpha;
    std::cout << "Remove from empty: " << dequeue(q, value) << '\n';

    for (int number = 1; number <= Queue::capacity; ++number) {
        enqueue(q, number);
    }

    std::cout << "Add 7 to full queue: " << enqueue(q, 7) << '\n';

    if (dequeue(q, value)) {
        std::cout << "First removed: " << value << '\n';
    }

    std::cout << "Add 7 after removal: " << enqueue(q, 7) << '\n';

    std::cout << "Remaining:";
    while (dequeue(q, value)) {
        std::cout << ' ' << value;
    }
    std::cout << '\n';
}

int main() {
    task_10_1_4();
    return 0;
}