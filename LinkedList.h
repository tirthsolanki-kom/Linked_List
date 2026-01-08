#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList();
    
    // Function to check if empty
    bool isEmpty();

    void insert(int val, int pos); // Custom function to insert anywhere

    void display();
};

#endif