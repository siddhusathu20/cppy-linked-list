/*
Python-style Linked List
by Siddharth Jai Gokulan
https://github.com/siddhusathu20/cppy-linked-list
*/

#ifndef SLINKEDLIST
#define SLINKEDLIST

#include <iostream>
#include <sstream>
#include <memory>

template <typename T> class LinkedList {
    private:
        struct Node {
            T data;
            int pos;
            Node* next;
        };
        Node* start = nullptr;
        Node* end = nullptr;
        int size = 0;
    public:
        void append(T ele);
        void insert(T ele, int pos);
        std::string str();
        T get(int pos);
        void set(int pos, T ele);
        T pop();
        T del(int pos);
        int len();
        ~LinkedList() {
            Node* currentEle =new Node;
            currentEle = start;
            while (currentEle != nullptr) {
                Node* delObj = currentEle;
                currentEle = currentEle->next;
                delete delObj;
            }
        }
};

template <typename T> int LinkedList<T>::len() {
    return size;
}

template <typename T> void LinkedList<T>::append(T ele) {
    if (start != nullptr) {
        Node* newNode = new Node;
        newNode->data = ele;
        newNode->pos = end->pos + 1;
        newNode->next = nullptr;
        end->next = newNode;
        end = newNode;
    } else {
        Node* newNode = new Node;
        newNode->data = ele;
        newNode->pos = 0;
        newNode->next = nullptr;
        start = end = newNode;
    }
    size += 1;
}

template <typename T> void LinkedList<T>::insert(T ele, int pos) {
    Node* currentEle = new Node;
    currentEle = start;
    while (currentEle != nullptr) {
        if (currentEle->pos == pos) {
            Node* newNode = new Node;
            newNode->data = ele;
            newNode->pos = pos + 1;
            newNode->next = currentEle->next;
            currentEle->next = newNode;
            currentEle = currentEle->next;
            size += 1;
        } else if (currentEle->pos > pos) {
            currentEle->pos++;
        }
        currentEle = currentEle->next;
    }
}

template <typename T> std::string LinkedList<T>::str() {
    Node* currentEle = new Node;
    std::ostringstream output;
    currentEle = start;
    if (currentEle != nullptr) {
        output << "[";
        while (currentEle->next) {
            output << currentEle->data << ", ";
            currentEle = currentEle->next;
        }
        output << currentEle->data << "]";
        return output.str();
    } else {
        return "[]";
    }
}

template <typename T> T LinkedList<T>::get(int pos) {
    Node* currentEle = new Node;
    currentEle = start;
    while (currentEle != nullptr) {
        if (currentEle->pos == pos) {
            return currentEle->data;
        }
        currentEle = currentEle->next;
    }
    return start->data;
}

template <typename T> void LinkedList<T>::set(int pos, T ele) {
    Node* currentEle = new Node;
    currentEle = start;
    while (currentEle != nullptr) {
        if (currentEle->pos == pos) {
            currentEle->data = ele;
            break;
        }
        currentEle = currentEle->next;
    }
}

template <typename T> T LinkedList<T>::pop() {
    if (end == nullptr) {
        throw std::runtime_error("No elements to delete!");
    } else if (start == end) {
        T endVal = end->data;
        start = end = nullptr;
        size -= 1;
        return endVal;
    } else {
        Node* currentEle = new Node;
        currentEle = start;
        int endPos = end->pos;
        while (currentEle != nullptr) {
            if (currentEle->pos == endPos - 1) {
                T endVal = end->data;
                currentEle->next = nullptr;
                end = currentEle;
                size -= 1;
                return endVal;
            }
            currentEle = currentEle->next;
        }
    }
    return 0;
}

template <typename T> T LinkedList<T>::del(int pos) {
    Node* currentEle = new Node;
    T delVal = get(pos);
    currentEle = start;
    while (currentEle != nullptr) {
        if (currentEle->pos == pos - 1) {
            currentEle->next = currentEle->next->next;
            size -= 1;
        } else if (currentEle->pos >= pos) {
            currentEle->pos--;
        }
        currentEle = currentEle->next;
    }
    return delVal;
}

#endif