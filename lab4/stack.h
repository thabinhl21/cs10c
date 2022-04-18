#ifndef __STACK_H__
#define __STACK_H__

template<typename T>
class Stack {
    private:
        const int MAX_SIZE = 20;
        T data[MAX_SIZE];
        int size;

    public:
        Stack();
        void push(T val);
        void pop();
        void pop_two();
        T top();
        bool empty();
};

#endif

