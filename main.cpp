#include "collections.cpp"

int main() {

    Queue<int>* q = new Queue<int>();
    for(int i = 0; i < 10; i++) {
        q->addData(i);
    }
    for(int i = 0; i < 10; i++) {
        q->get();
    }

    Stack<int>* s = new Stack<int>();
    for(int i = 0; i < 10; i++) {
        s->addData(i);
    }
    for(int i = 0; i < 10; i++) {
        s->get();
    }

    return 0;
}