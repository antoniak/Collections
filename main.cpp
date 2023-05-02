#include "collections.cpp"

int main() {

    Queue<int> q;
    for(int i = 0; i < 10; i++) {
        q.add(i);
    }
    for(int i = 0; i < 10; i++) {
        q.get();
    }

    Stack<int> s;
    for(int i = 0; i < 10; i++) {
        s.add(i);
    }
    for(int i = 0; i < 10; i++) {
        s.get();
    }

    return 0;
}