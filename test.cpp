#include "gtest/gtest.h"
#include "collections.cpp"


// Queue - add()
TEST(Queue, addInt) {
    Queue<int> q;
    for(int i = 0; i < 10; i++) {
        q.add(i);
    }
    for(int i = 0; i < 10; i++) {
        EXPECT_EQ(q.get(), i);
    }
}

// Queue - add()
TEST(Queue, addFloat) {
    Queue<float> q;
    q.add(1.3);
    q.add(5.9);
    EXPECT_FLOAT_EQ(q.get(), 1.3);
    EXPECT_FLOAT_EQ(q.get(), 5.9);
}

// Queue - get()
TEST(Queue, get) {
    Queue<int> q;
    q.add(1);
    q.add(2);
    EXPECT_EQ(q.get(), 1);
    EXPECT_EQ(q.get(), 2);
    EXPECT_EXIT(q.get(), ::testing::ExitedWithCode(1), "Error: The Queue is Empty.");
    q.add(3);
    EXPECT_EQ(q.get(), 3);
    EXPECT_EXIT(q.get(), ::testing::ExitedWithCode(1), "Error: The Queue is Empty.");
}

// Queue - isEmpty()
TEST(Queue, isEmpty) {
    Queue<std::string> q;
    EXPECT_EQ(q.isEmpty(), true);
    q.add("one");
    EXPECT_EQ(q.isEmpty(), false);
    q.get();
    EXPECT_EQ(q.isEmpty(), true);
}

// Queue - size()
TEST(Queue, size) {
    Queue<int> q;
    EXPECT_EQ(q.size(), 0);
    for(int i = 0; i < 10; i++) {
        q.add(i);
    }
    EXPECT_EQ(q.size(), 10);
    for(int i = 0; i < 5; i++) {
        q.get();
    }
    EXPECT_EQ(q.size(), 5);
    for(int i = 0; i < 5; i++) {
        q.get();
    }
    EXPECT_EQ(q.size(), 0);
}

// Stack - add()
TEST(Stack, add) {
    Stack<int> s;
    for(int i = 0; i < 10; i++) {
        s.add(i);
    }
    for(int i = 9; i > -1; i--) {
        EXPECT_EQ(s.get(), i);
    }
}

// Stack - get()
TEST(Stack, get) {
    Stack<int>* s = new Stack<int>();
    s->add(1);
    s->add(2);
    EXPECT_EQ(s->get(), 2);
    EXPECT_EQ(s->get(), 1);
    EXPECT_EXIT(s->get(), ::testing::ExitedWithCode(1), "Error: The Stack is Empty.");
    s->add(3);
    s->add(4);
    EXPECT_EQ(s->get(), 4);
    EXPECT_EQ(s->get(), 3);
    EXPECT_EXIT(s->get(), ::testing::ExitedWithCode(1), "Error: The Stack is Empty.");
    delete s;
}

// Stack - isEmpty()
TEST(Stack, isEmpty) {
    Queue<std::string> s;
    EXPECT_EQ(s.isEmpty(), true);
    s.add("one");
    EXPECT_EQ(s.isEmpty(), false);
    s.get();
    EXPECT_EQ(s.isEmpty(), true);
}

// Queue - size()
TEST(Stack, size) {
    Queue<int> s;
    EXPECT_EQ(s.size(), 0);
    for(int i = 0; i < 10; i++) {
        s.add(i);
    }
    EXPECT_EQ(s.size(), 10);
    for(int i = 0; i < 5; i++) {
        s.get();
    }
    EXPECT_EQ(s.size(), 5);
    for(int i = 0; i < 5; i++) {
        s.get();
    }
    EXPECT_EQ(s.size(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}