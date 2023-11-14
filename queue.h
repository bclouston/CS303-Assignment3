//
//  queue.h
//  CS303A3
//
//  Created by Brendan Clouston on 11/9/23.
//

#ifndef queue_h
#define queue_h

struct Node {
    int data;
    Node* nextPtr;
};

class Queue {
private:
    Node* front;
    Node* tail;
    Node* num_items;
public:
    //default constructor, creates empty list
    Queue() {
        front = nullptr;
        tail = nullptr;
        num_items = 0;
    };
    
    //overloaded constructor, creates list and element from item passed
    Queue(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->nextPtr = nullptr;
        front = newNode;
        tail = newNode;
        num_items = 1;
    };
    
    //returns a boolean response whether queue is empty
    //PRE: queue has been constructed
    //POST: returns true if queue is empty, false otherwise
    bool empty() {
        if (headPtr == nullptr) { return true; }
        else { return false; }
    };
    
    //return queue size
    //PRE: quque has been constructed
    //POST: returns number of items in queue
    int size() { return num_items; };
    
    //add item to end of list
    //PRE: accepts int
    //POST: creates new queue node and inserts at the end
    void push_back(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->nextPtr = nullptr;
        tail->nextPtr = newNode;
        tail = newNode;
        //check if list was empty and initialize front
        if (front == nullptr) {
            front = newNode;
        }
        num_items++;
    };
    
    //removes first item in queue
    //PRE: queue has at least one element
    //POST: returns the node at front of the queue
    void pop() {
        if (front == nullptr) {
            cout << "Can not delete from an empty list" << endl;
            return;
        }
        Node* delNode = front;
        front = front->nextPtr;
        num_items--;
        return delNode;
    };
    
    //
    //PRE:
    //POST:
    Node* front() {
        if (headPtr == nullptr) {
            cout << "Can not return element from an empty list" << endl;
            return nullptr;
        }
        else { return front; }
    };
};

#endif /* queue_h */
