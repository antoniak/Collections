#include<iostream>
#include<cassert>

template <class K> class Queue;
template <class K> class Stack;

template <class T>
class Node {
    friend class Queue<T>;
    friend class Stack<T>;

private:
    Node* next;
    T data;
    size_t len;

    Node(T x): data(x) { next = nullptr; }
    ~Node() { delete next; }
};

// Queue
template <class K> 
class Queue {
private:
    Node<K>* head;
    Node<K>* tail;
    size_t len;

public:
    // Initialises the empty queue.
    Queue() {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }
    
    // Deallocates the memory occupied by the queue.
    ~Queue() {
        delete head;
    }

    
    // Adds an element in the queue.
    void add(K x) {
        Node<K>* node = new Node<K>(x); // create new node
        if(tail == nullptr) { // the queue is empty
            assert((head == nullptr) && (len == 0)); // checks conditions implied by emptyness
            tail = node; 
            head = node; 
            len++; 
            return;
        }      

        // the queue is not empty
        tail->next = node;
        tail = node;
        len++;
        return;
    }

     
    // Removes the earliest inserted element and returns that element.
    K get() {
        if(head == nullptr) { // the queue is empty
            assert((tail == nullptr) && (len == 0)); // checks conditions implied by emptyness
            std::cerr << "Error: The Queue is Empty." << std::endl;
            exit(1);
        }

        K d = head->data;
        Node<K>* curr = head;

        if(head->next != nullptr) { // size of the queue greater than one
            
            head = head->next;
            len--;

            // deallocate memory
            curr->next = nullptr;
            delete curr;
            
            return d;
        } 
        
        // size of queue is one
        len--; assert(len == 0); 
        head = tail = nullptr;

        // deallocate memory
        curr->next = nullptr;
        delete curr;
        
        return d; 
    }

    
    // Returns true if the queue is empty, otherwise returns false.
    bool isEmpty() { return (len == 0); }

    
    // Returns the size of the queue.
    size_t size() { return len; }

};

// Stack
template<class K>
class Stack {

private:
    Node<K>* top;
    size_t len;

public:
    // Initialises the empty stack.
    Stack() {
        top = nullptr;
        len = 0;
    }
    
    // Deallocates the memory occupied by the stack.
    ~Stack() {
        delete top;
    }

    
    // Adds an element in the stack.
    void add(K x) {
        Node<K>* node = new Node<K>(x); // creates a new node     
        if(top == nullptr) { // stack is empty
            assert(len == 0); 
            top = node;
            len++;
            return;
        } 

        // stack is not empty
        node->next = top;
        top = node;   
        len++;     
        return;
    }

    
    // Removes the most recently inserted element and returns that element.
    K get() {
        if(top == nullptr) { // stack is empty
            assert(len == 0);
            std::cerr << "Error: The Stack is Empty." << std::endl;
            exit(1);
        }
        
        // stack is not empty
        K d = top->data; 
        Node<K>* curr = top; 

        top = top->next;
        len--;

        // deallocate memory
        curr->next = nullptr; 
        delete curr;
        
        return d;
    }

    
    // Returns true if the stack is empty, otherwise returns false.
    bool isEmpty() {
        return (len == 0);
    }

    
    // Returns the size of the stack.
    size_t size() {
        return len;
    }

};