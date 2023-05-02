#include "gtest/gtest.h"
#include "collections.cpp"


// Queue - addData()
TEST(Queue, addDataInt) {
    Queue<int>* q = new Queue<int>();
    for(int i = 0; i < 10; i++) {
        q->addData(i);
    }
    for(int i = 0; i < 10; i++) {
        EXPECT_EQ(q->get(), i);
    }
}

// Queue - addData()
TEST(Queue, addDataFloat) {
    Queue<float>* q = new Queue<float>();
    q->addData(1.3);
    q->addData(5.9);
    EXPECT_FLOAT_EQ(q->get(), 1.3);
    EXPECT_FLOAT_EQ(q->get(), 5.9);
}

// Queue - get()
TEST(Queue, get) {
    Queue<int>* q = new Queue<int>();
    q->addData(1);
    q->addData(2);
    EXPECT_EQ(q->get(), 1);
    EXPECT_EQ(q->get(), 2);
    EXPECT_EXIT(q->get(), ::testing::ExitedWithCode(1), "Error: The Queue is Empty.");
    q->addData(3);
    EXPECT_EQ(q->get(), 3);
    EXPECT_EXIT(q->get(), ::testing::ExitedWithCode(1), "Error: The Queue is Empty.");
}

// Queue - isEmpty()
TEST(Queue, isEmpty) {
    Queue<std::string>* q = new Queue<std::string>();
    EXPECT_EQ(q->isEmpty(), true);
    q->addData("one");
    EXPECT_EQ(q->isEmpty(), false);
    q->get();
    EXPECT_EQ(q->isEmpty(), true);
}

// Queue - size()
TEST(Queue, size) {
    Queue<int>* q = new Queue<int>();
    EXPECT_EQ(q->size(), 0);
    for(int i = 0; i < 10; i++) {
        q->addData(i);
    }
    EXPECT_EQ(q->size(), 10);
    for(int i = 0; i < 5; i++) {
        q->get();
    }
    EXPECT_EQ(q->size(), 5);
    for(int i = 0; i < 5; i++) {
        q->get();
    }
    EXPECT_EQ(q->size(), 0);
}

// Stack - addData()
TEST(Stack, addData) {
    Stack<int>* s = new Stack<int>();
    for(int i = 0; i < 10; i++) {
        s->addData(i);
    }
    for(int i = 9; i > -1; i--) {
        EXPECT_EQ(s->get(), i);
    }
}

// Stack - get()
TEST(Stack, get) {
    Stack<int>* s = new Stack<int>();
    s->addData(1);
    s->addData(2);
    EXPECT_EQ(s->get(), 2);
    EXPECT_EQ(s->get(), 1);
    EXPECT_EXIT(s->get(), ::testing::ExitedWithCode(1), "Error: The Stack is Empty.");
    s->addData(3);
    s->addData(4);
    EXPECT_EQ(s->get(), 4);
    EXPECT_EQ(s->get(), 3);
    EXPECT_EXIT(s->get(), ::testing::ExitedWithCode(1), "Error: The Stack is Empty.");
}

// Stack - isEmpty()
TEST(Stack, isEmpty) {
    Queue<std::string>* s = new Queue<std::string>();
    EXPECT_EQ(s->isEmpty(), true);
    s->addData("one");
    EXPECT_EQ(s->isEmpty(), false);
    s->get();
    EXPECT_EQ(s->isEmpty(), true);
}

// Queue - size()
TEST(Stack, size) {
    Queue<int>* s = new Queue<int>();
    EXPECT_EQ(s->size(), 0);
    for(int i = 0; i < 10; i++) {
        s->addData(i);
    }
    EXPECT_EQ(s->size(), 10);
    for(int i = 0; i < 5; i++) {
        s->get();
    }
    EXPECT_EQ(s->size(), 5);
    for(int i = 0; i < 5; i++) {
        s->get();
    }
    EXPECT_EQ(s->size(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}