#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <string>
#include <fstream> // For file handling
#include <map>

using namespace std;


void LoginScreen();
void printBoxedMessage(const string& message);



// Node structure
struct Node {
    string data;
    Node* next;
    Node* prev;
    Node(string val) : data(val), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List Class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insert(string data);
    Node* search(string key);
    void remove(string key);
    void sort();
    void destroy();
    void display();

    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
};
#endif

