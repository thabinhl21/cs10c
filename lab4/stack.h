#ifndef __STACK_H__
#define __STACK_H__

#include <stdexcept>

template<typename T>
class stack {
    private:
        static const int MAX_SIZE = 20;
        T data[MAX_SIZE];
        int size;

    public:
        stack<T>() {
            size = 0;
        }

        void push(T val) {
            if (size > MAX_SIZE) {
                throw overflow_error("Called push on full stack");
            }
            for (int i = 0; i < size; i++) {
                data[i] = val;
            }
        }

        void pop() {
            if (size == 0) {
                throw out_of_range("Called pop on empty stack");
            }
            size -= 1;
        }

        void pop_two() {
            if (size == 1) {
                throw out_of_range("Called pop_two on a stack of size 1");
            }
            else if (size == 0) {
                throw out_of_range("Called pop_two on empty stack");
            }
            size -= 2;
        }

        T top() {
            if (size == 0) {
                throw underflow_error("Called top on empty stack");
            }
            return data[size - 1];
        }

        bool empty() {
            if (size == 0) {
                return true;
            }
            else {
                return false;
            }
        }
};

#endif

