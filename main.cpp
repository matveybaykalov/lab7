#include <iostream>

struct Node{
    Node* next;
    int value;
};

struct Queue{
    Node* first;
    Node* last;
};

Queue constructor (){
    Queue result;
    result.first = nullptr;
    result.last = nullptr;
    return result;
}

void destructor (Queue& queue){
    while (queue.first != queue.last){
        Node* temp;
        temp = queue.first;
        queue.first = temp->next;
        delete temp;
    }
    queue.first = nullptr;
    queue.last = nullptr;
}

void push (Queue& queue, int value){
    Node *node = new Node;
    if (queue.first == nullptr){
        queue.first = node;
    } else {
        queue.last->next = node;
    }
    queue.last = node;
    node->next = nullptr;
    node->value = value;
}

unsigned int size(const Queue& queue){
    unsigned int counter = 0;
    if (queue.first != nullptr) {
        counter++;
        Node *iter = queue.first;
        while (iter != queue.last) {
            ++counter;
            iter = iter->next;
        }
    }
    return counter;
}

int pop(Queue& queue){
    Node* temp;
    temp = queue.first;
    queue.first = temp->next;
    int result = temp->value;
    delete temp;
    return result;
}

void print(const Queue& queue){
    Node* iter = queue.first;
    while (iter != nullptr){
        std::cout << iter->value << ' ';
        iter = iter->next;
    }
    std::cout << std::endl;
}
int main() {
    Queue queue;
    queue = constructor();
    std::cout << size(queue) << std::endl;
    push(queue, 10);
    push(queue, 20);
    push(queue, 30);
    push(queue, 40);
    push(queue, 50);
    print(queue);
    std::cout << size(queue) << std::endl;
    std::cout << pop(queue) << std::endl;
    std::cout << pop(queue) << std::endl;
    print(queue);
    std::cout << size(queue) << std::endl;
    destructor(queue);
    return 0;
}
