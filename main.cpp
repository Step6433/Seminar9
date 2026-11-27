#include <iostream>

struct Queue {
    static constexpr int capacity = 6;

    int data[capacity]{};
    int head = 0;
    int tail = 0;
    int count = 0;
};

void printQueue(const Queue& q) {
    std::cout << "Queue: [";
    for (int i = 0; i < q.count; ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << q.data[(q.head + i) % Queue::capacity];
    }
    std::cout << "] (head=" << q.head << ", tail=" << q.tail
              << ", count=" << q.count << ")\n";
}

bool enqueue(Queue& q, int value) {
    if (q.count == Queue::capacity) {
        return false;
    }

    q.data[q.tail] = value;
    q.tail = (q.tail + 1) % Queue::capacity;
    ++q.count;
    std::cout << "enqueue(" << value << ") -> ";
    printQueue(q);
    return true;
}

bool dequeue(Queue& q, int& value) {
    if (q.count == 0) {
        return false;
    }

    value = q.data[q.head];
    q.head = (q.head + 1) % Queue::capacity;
    --q.count;
    std::cout << "dequeue (removed " << value << ") -> ";
    printQueue(q);
    return true;
}

void task_10_1_4() {
    Queue q;
    int value = 0;

    std::cout << "Task 10.1.4\n" << std::boolalpha;
    std::cout << "Remove from empty: " << dequeue(q, value) << '\n';

    for (int number = 1; number <= Queue::capacity; ++number) {
        enqueue(q, number);
    }

    std::cout << "Add 7 to full queue: " << enqueue(q, 7) << '\n';

    if (dequeue(q, value)) {
        std::cout << "First removed: " << value << '\n';
    }

    bool added = enqueue(q, 7);
    std::cout << "Add 7 after removal: " << added << '\n';

    std::cout << "Removing remaining elements:\n";
    while (dequeue(q, value)) {
    }
    std::cout << '\n';
}

struct Deque {
    static constexpr int capacity = 6;

    int data[capacity]{};
    int head = 0;
    int count = 0;
};

void printDeque(const Deque& d) {
    std::cout << "Deque: [";
    for (int i = 0; i < d.count; ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << d.data[(d.head + i) % Deque::capacity];
    }
    std::cout << "] (head=" << d.head << ", count=" << d.count << ")\n";
}

bool pushFront(Deque& d, int value) {
    if (d.count == Deque::capacity) {
        return false;
    }

    d.head = (d.head + Deque::capacity - 1) % Deque::capacity;
    d.data[d.head] = value;
    ++d.count;
    std::cout << "pushFront(" << value << ") -> ";
    printDeque(d);
    return true;
}

bool pushBack(Deque& d, int value) {
    if (d.count == Deque::capacity) {
        return false;
    }

    int index = (d.head + d.count) % Deque::capacity;
    d.data[index] = value;
    ++d.count;
    std::cout << "pushBack(" << value << ") -> ";
    printDeque(d);
    return true;
}

bool popFront(Deque& d, int& value) {
    if (d.count == 0) {
        return false;
    }

    value = d.data[d.head];
    d.head = (d.head + 1) % Deque::capacity;
    --d.count;
    std::cout << "popFront (removed " << value << ") -> ";
    printDeque(d);
    return true;
}

bool popBack(Deque& d, int& value) {
    if (d.count == 0) {
        return false;
    }

    int index = (d.head + d.count - 1) % Deque::capacity;
    value = d.data[index];
    --d.count;
    std::cout << "popBack (removed " << value << ") -> ";
    printDeque(d);
    return true;
}

void task_10_1_5() {
    Deque d;
    int value = 0;

    std::cout << "\nTask 10.1.5\n" << std::boolalpha;

    pushBack(d, 10);
    pushBack(d, 20);
    pushFront(d, 5);

    if (popBack(d, value)) {
        std::cout << "popBack: " << value << '\n';
    }

    pushFront(d, 1);
    if (popFront(d, value)) {
        std::cout << "popFront: " << value << '\n';
    }
    pushBack(d, 30);

    std::cout << "Removing remaining elements:\n";
    while (popFront(d, value)) {
    }
    std::cout << '\n';

    std::cout << "Pop from empty (front/back): "
              << popFront(d, value) << ' ' << popBack(d, value) << '\n';

    for (int number = 1; number <= Deque::capacity; ++number) {
        pushBack(d, number);
    }

    std::cout << "Push into full (front/back): "
              << pushFront(d, 7) << ' ' << pushBack(d, 7) << '\n';
}

int main() {
    task_10_1_4();
    task_10_1_5();
}
