#include "LinkedList.h"
#include <iostream>

// Constructor logic using the initializer list
LinkedList::LinkedList() : head(nullptr) {}

// Check if empty
bool LinkedList::isEmpty() {
    return head == nullptr;
}


void LinkedList::insert(int val, int pos) {
    Node* newNode = new Node();
    newNode->data = val;

    // Case 1: Insert at the beginning (Position 0)
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Insert in middle or at the end
    Node* temp = head;
    // Move to the node right before the target position
    for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    // Check if the position is valid
    if (temp == nullptr) {
        std::cout << "Error: Position out of bounds!" << std::endl;
        delete newNode; // Cleanup to avoid memory leak
        return;
    }

    // The "Rewire": Link the new node, then update the previous node
    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}

void LinkedList::remove(int val) {
	Node* cur = head;
	Node* prev = nullptr;
	while (cur) {
		if (cur->data == val) {
			Node* toDelete = cur;
			if (prev)
				prev->next = cur->next;
			else
				head = cur->next;
			cur = cur->next;
			delete toDelete;
		} else {
			prev = cur;
			cur = cur->next;
		}
	}
}

void LinkedList::update(int oldVal, int newVal) {
	Node* cur = head;
	while (cur) {
		if (cur->data == oldVal) {
			cur->data = newVal;
		}
		cur = cur->next;
	}
}

// Destructor to free nodes
LinkedList::~LinkedList() {
	Node* cur = head;
	while (cur) {
		Node* next = cur->next;
		delete cur;
		cur = next;
	}
}

