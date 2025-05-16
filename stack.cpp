#include <iostream>
#include <vector>
#include <stdexcept>

// Stack Class
class Stack {
private:
    std::vector<int> items;

public:
    void push(int item) {
        items.push_back(item);
    }

    int pop() {
        if (items.empty()) {
            throw std::out_of_range("Stack is empty, cannot pop.");
        }
        int top = items.back();
        items.pop_back();
        return top;
    }

    friend std::ostream& operator<<(std::ostream& os, const Stack& stack) {
        os << "Stack(top -> bottom): [";
        for (auto it = stack.items.rbegin(); it != stack.items.rend(); ++it) {
            os << *it;
            if (it + 1 != stack.items.rend()) os << ", ";
        }
        os << "]";
        return os;
    }
};

// Queue Class
class Queue {
private:
    std::vector<int> items;

public:
    void enqueue(int item) {
        items.push_back(item);
    }

    int dequeue() {
        if (items.empty()) {
            throw std::out_of_range("Queue is empty, cannot dequeue.");
        }
        int frontItem = items.front();
        items.erase(items.begin());
        return frontItem;
    }

    friend std::ostream& operator<<(std::ostream& os, const Queue& queue) {
        os << "Queue(front -> rear): ";
        for (size_t i = 0; i < queue.items.size(); i++) {
            os << queue.items[i];
            if (i != queue.items.size() - 1) os << " -> ";
        }
        return os;
    }
};

int main() {
    // Stack demonstration
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << stack << std::endl;  // Stack(top -> bottom): [30, 20, 10]

    try {
        std::cout << "Popped: " << stack.pop() << std::endl;  // Popped: 30
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << stack << std::endl;  // Stack(top -> bottom): [20, 10]

    // Queue demonstration
    Queue queue;
    queue.enqueue(100);
    queue.enqueue(200);
    queue.enqueue(300);
    std::cout << queue << std::endl;  // Queue(front -> rear): 100 -> 200 -> 300

    try {
        std::cout << "Dequeued: " << queue.dequeue() << std::endl;  // Dequeued: 100
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << queue << std::endl;  // Queue(front -> rear): 200 -> 300

    return 0;
}
