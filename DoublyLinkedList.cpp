#include "DoublyLinkedList.h"

// Constructor
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Destructor

DoublyLinkedList::~DoublyLinkedList() { destroy();}


void DoublyLinkedList::insert(string data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

Node* DoublyLinkedList::search(string key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void DoublyLinkedList::remove(string key) {
    Node* target = search(key);
    if (target == nullptr) {
        cout << "Item not found!" << endl;
        return;
    }
    if (target->prev != nullptr) {
        target->prev->next = target->next;
    } else {
        head = target->next;
    }
    if (target->next != nullptr) {
        target->next->prev = target->prev;
    } else {
        tail = target->prev;
    }
    delete target;
    cout << "Item removed!" << endl;
}

void DoublyLinkedList::sort() {
    if (head == nullptr)
    {
        cout << "The list is empty";
        return;

    }
    bool swapped;
    Node* current;
    do {
        swapped = false;
        current = head;
        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void DoublyLinkedList::destroy() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = tail = nullptr;
    
}

void DoublyLinkedList::display() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }
    cout << endl;
}




void DoublyLinkedList::saveToFile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        printBoxedMessage("Error: Unable to open file for saving." );
        return;
    }else printBoxedMessage("Library saved to file successfully!");

    Node* current = head;
    while (current) {
        file << current->data << endl; // Write each node's data to a new line
        current = current->next;
    }

    file.close();
}

void DoublyLinkedList::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        printBoxedMessage("Error: Unable to open file for loading.");
        return;
    }else printBoxedMessage("Library loaded from file successfully!");

    destroy(); // Clear the current list

    string line;
    while (getline(file, line)) {
        insert(line); // Insert each line as a new node
    }

    file.close();
}


