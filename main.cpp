#include <iostream>

struct Node{
    Node* previous;
    int value;
};

struct Stack{
    Node* last;
};

Stack constructor (){
    Stack result;
    result.last = nullptr;
    return result;
}

void destructor (Stack& stack){
    while (stack.last != nullptr){
        Node* temp;
        temp = stack.last;
        stack.last = temp->previous;
        delete temp;
    }
}

void push (Stack& stack, int value){
    if (stack.last == nullptr){
        Node *node = new Node;
        node->previous = nullptr;
        node->value = value;
        stack.last = node;
    } else {
        Node *node = new Node;
        node->previous = stack.last;
        node->value = value;
        stack.last = node;
    }
}

unsigned int size(const Stack& stack){
    unsigned int counter = 0;
    Node* iter = stack.last;
    while (iter != nullptr){
        ++counter;
        iter = iter->previous;
    }
    return counter;
}

int pop(Stack& stack){
    Node* temp;
    temp = stack.last;
    stack.last = temp->previous;
    int result = temp->value;
    delete temp;
    return result;
}

void print(const Stack& stack){
    Node* iter = stack.last;
    while (iter != nullptr){
        std::cout << iter->value << ' ';
        iter = iter->previous;
    }
    std::cout << std::endl;
}

int main() {
    Stack stack;
    stack = constructor();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    print(stack);
    std::cout << size(stack) << std::endl;
    std::cout << pop(stack) << std::endl;
    std::cout << pop(stack) << std::endl;
    print(stack);
    std::cout << size(stack) << std::endl;
    destructor(stack);
    return 0;
}
