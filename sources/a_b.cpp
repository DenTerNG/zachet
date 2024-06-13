// a_b.cpp
#include "a_b.hpp"

A::A() {
    b = new B();
}

int A::f1(int number) {
    return b->somefunc(number);
}

int B::somefunc(int number) {
    return number % 5 == 0 ? 1 : 0;
}
