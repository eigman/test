#include "stack.h"
#include <iostream>

Stack::~Stack() {
    while (!*this) {
        pop();
    }
}

Stack :: Stack(const Stack& other) {
    top = nullptr;
    Node* current = other.top;
    while (current != nullptr) {
        push(current->data);
        current = current->next;
    }
}

void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

int Stack::pop() {
    if (!*this) {
        std::cerr << "Стек пуст." << std::endl;
        return -1;
    }
    Node* temp = top;
    int poppedValue = top->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

bool operator!(const Stack& stack) {
    return stack.top == nullptr;
}

void operator++(Stack& stack) {
    Node* current = stack.top;
    int maxVal = current->data;
    while (current != nullptr) {
        if (current->data > maxVal) {
            maxVal = current->data;
        }
        current = current->next;
    }
    current = stack.top;
    while (current != nullptr) {
        current->data += maxVal;
        current = current->next;
    }
}

void operator++(Stack& stack, int) {
    Node* current = stack.top;
    int minVal = current->data;
    while (current != nullptr) {
        if (current->data < minVal) {
            minVal = current->data;
        }
        current = current->next;
    }
    current = stack.top;
    while (current != nullptr) {
        current->data += minVal;
        current = current->next;
    }
}

void Stack::operator--() {
    Node* current = top;
    int maxVal = current->data;
    while (current != nullptr) {
        if (current->data > maxVal) {
            maxVal = current->data;
        }
        current = current->next;
    }
    current = top;
    while (current != nullptr) {
        current->data -= maxVal;
        current = current->next;
    }
}

void Stack::operator--(int) {
    Node* current = top;
    int minVal = current->data;
    while (current != nullptr) {
        if (current->data < minVal) {
            minVal = current->data;
        }
        current = current->next;
    }
    current = top;
    while (current != nullptr) {
        current->data -= minVal;
        current = current->next;
    }
}


void Stack::display() const {
    Node* current = top;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
