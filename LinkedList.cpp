#include "LinkedList.h"
#include <iostream>

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
    container = _head->data; // Why not _head->next->data?;
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
    printList();
    return stream;
}



/* 
        MAIN/DRIVER
 */

int main() {
    LinkedList<int> testList;

    testList.push(5);
    testList.push(9);
    testList.push(17);
    testList.push(63);
    
    int temp = 0;
    testList.pop(temp);
    testList.peek(temp);
    testList.printList();
    testList.emptyThisList();
    testList.printList();
}
