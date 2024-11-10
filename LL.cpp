#include <iostream>
#include <algorithm>
#include "BSTLL.h"
#include "RNG.h"

void LinkedList::clear() {
    LinkedListNode *current = head;

    while (current != nullptr) {
        LinkedListNode *nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList() {

    LinkedListNode* tmp = head, *rmv;

    while (tmp != nullptr) {
        rmv = tmp;
        tmp = tmp->next;
        delete rmv;
    }

    head = nullptr;
    tail = nullptr;
    
}

LinkedList::LinkedList(const LinkedList& ll) {
    LinkedListNode* tmp = head;
    head = nullptr;
    tail = nullptr;

    while(tmp != nullptr) {
        append(tmp->data);
        tmp = tmp->next;
    }
}

bool LinkedList::append(int val) {
    LinkedListNode* tmp = new LinkedListNode(val);
    
    if(head == nullptr) {
        head = tmp;
    } else {
        tail->next = tmp;
    }

    tail = tmp;
    return true;
}

bool LinkedList::prepend(int val) {
    LinkedListNode* tmp = new LinkedListNode(val);
    
    if(head == nullptr) {
        tail = tmp;
    }

    tmp->next = head;
    head = tmp;
}


bool LinkedList::search(int val) {

    LinkedListNode* tmp = head;

    while(tmp != nullptr) {

        if (tmp->data == val) {
            return true;
        }
        tmp = tmp->next;
    }

    return false;
}
    
bool LinkedList::remove(int val) {
    LinkedListNode* tmp = head;
    LinkedListNode* prv = nullptr;

    while(tmp != nullptr) {

        if (tmp->data == val) {
            prv->next = tmp->next;

            delete tmp;
            return true;
        }

        prv = tmp;
        tmp = tmp->next;
    }
}
    
void LinkedList::display(std::ostream& os) {
    LinkedListNode* tmp = head;

    while (tmp != nullptr){
        os << tmp->data << ", ";
        tmp = tmp->next;
    }
}


std::ostream &operator<<(std::ostream& os, LinkedList& ll) {
    ll.display(os);
    return(os);
}