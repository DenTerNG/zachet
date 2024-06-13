// a_b.h
#pragma once

class B {
public:
    int somefunc(int number);
};

class A {
public:
    A();
    int f1(int number);

private:
    B* b;
};
