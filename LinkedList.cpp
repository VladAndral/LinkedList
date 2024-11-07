#include "LinkedList.h"
#include <iostream>
#include <vector>

using std::cout, std::cin; // Multiple declarators in single line is a C++17 extention

template<class T>
LinkedList<T>::LinkedList() : _head(nullptr), _size(0) {    }

template <class T>
LinkedList<T>::~LinkedList() {
    int temp = 0;
    while (pop(temp));
}

template <class T>
bool LinkedList<T>::push(T value) {
    Node<T> *toAdd = new Node<T>; // We need to create a new node! Not just initialize one! toAdd is a POINTER
    toAdd->data = value; // toAdd is a pointer!
    toAdd->next = _head; // Why is it not _head->next?
    _head = toAdd;
    _size++;
    return true;
}

template <class T>
bool LinkedList<T>::pop(T &container) {

    if (_head == nullptr) {
        return false;
    }
    container = _head->data; // Why not _head->next->data? Because _head is only a POINTER! Head is almost the object.
    Node<T> *temp = _head;
    _head = _head->next;
    delete temp;
    _size--;
    return true;

}

template <class T>
bool LinkedList<T>::peek(T &container) {
    container = _head->data;
    return true;
}

template <class T>
bool LinkedList<T>::insert(T value) {
    Node<T> *toInsert = new Node<T>; // Follow this structure when creating new Nodes; Node object, then manually add data
    toInsert->data = value;

    if (_head == nullptr) { // Empty list
        _head = toInsert;
    } else if (toInsert->data < _head->data) { // If insert needs to happen first
            toInsert->next = _head;
            _head = toInsert;
            // if (_head->next == nullptr) { // If insert needs to happen first but head points to null
            //     toInsert->next = _head;
            //     _head = toInsert;
            // } else {
            //     _head = toInsert;
            //     toInsert = _head->next;
            // }
    } else {
        
        Node<T> *checkPointer = _head;

        while (checkPointer->next != nullptr) { // Iterate thru list
            if (value <= checkPointer->next->data) { // If the next value is bigger, we know where to insert
                break;
            }
            // checkPointer++; WRONG!! This is NOT a contiguous block of memory!! Not an array!
            checkPointer = checkPointer->next;
        }
        
        // Adding the object toInsert points to in the list
        toInsert->next = checkPointer->next;
        checkPointer->next = toInsert;
    }

    return true;

    
}

template <class T>
int LinkedList<T>::size() {
    return _size;
}

template <class T>
bool LinkedList<T>::emptyThisList() {
    int temp = 0;
    while (pop(temp));
    return true;
}

template <class T>
bool LinkedList<T>::isListEmpty() {
    return (_size == 0);
}

template <class T>
void LinkedList<T>::printList()
{

    if (_head == nullptr) {
        cout << "List is empty." << std::endl;
    } else {
        Node<T> currNode = *_head;
        while (currNode.next != nullptr) {
            cout << currNode.data << std::endl;
            currNode = *currNode.next;
        }
        cout << currNode.data << std::endl; // Fencepost problem
    }
}

template <class T>
ostream &operator<<(ostream &stream, const LinkedList<T> linkedList) {
    linkedList.printList();
    return stream;
}



/* 
        MAIN/DRIVER
 */

int main(int argc, char *argv[]) {
    LinkedList<int> testList;

    // testList.push(5);
    // testList.push(9);
    // testList.push(17);
    // testList.push(63);
    
    // int temp = 0;
    // testList.pop(temp);
    // testList.peek(temp);
    // testList.printList();
    // testList.emptyThisList();
    // testList.printList();

    // testList.push(63); // Must be in order
    // testList.push(17);
    // testList.push(9);
    // testList.push(5);
    testList.insert(40);
    testList.insert(17);
    testList.insert(9);
    testList.insert(63);
    testList.insert(5);
    testList.printList();
    
}
