#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_


#include <iostream>

using std::cout, std::ostream, std::istream; // Multiple declarators in single line is a C++17 extention

template<class T>
struct Node {
    T data;
    Node *next = nullptr; // A pointer to another Node
};

template<class T>
class LinkedList {
    public:

        LinkedList();
        LinkedList(LinkedList &toCopy); //TODO: To initialize w/ data from another LL, must make deep copy
        ~LinkedList(); // Deconstructor

        bool push(T value); // not T &container
        bool pop(T &container); // return the value in the object that was passed in, hence 'container'
        bool peek(T &container); // like pop, but don't remove value from LinkedList
        bool insert(T value); // Caveat: List MUST be sorted!
        int size(); // Rather than count each time, size should be updated with every push and pop (because otherwise, would have to go thru iteratively, and there are no shortcuts b/c objects are not contiguous)
        bool emptyThisList(); 
        bool isListEmpty(); 
        void printList();
        
        //TODO: Operators? Specify for only numbers? Compare lists?
        friend ostream &operator<<(ostream &stream, const LinkedList<T> linkedList);

    private:
        
        /* 
            The ONLY field in a linked list is a pointer [NOT a Node object!!] to the first element in the LinkedList.
            All other Nodes point to the next one. Also keep in mind that a LinkedList has stack functionality,
            so we only need to operate on what's on top.
         */
        Node<T> *_head; // You MUST add Node<T> if you are templatizing!
        int _size;


};


#endif