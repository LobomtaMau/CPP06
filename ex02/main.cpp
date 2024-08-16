#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate() {
    srand(static_cast<unsigned int>(time(0)));
    int r = rand() % 3;

    switch (r) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return NULL;
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B *>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C *>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown type\n";
}

void identify(Base &p) {
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A\n";
    }
    catch (std::exception &e) {}

    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "B\n";
    }
    catch (std::exception &e) {}

    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C\n";
    }
    catch (std::exception &e) {}
}

int main () {
    Base *base = generate();

    std::cout << "Identify with pointer: \n";
    identify(base);

    std::cout << "Identify with reference: \n";
    identify(*base);

    delete base;

    return 0;
}





/*
This exercise is designed to deepen your understanding of how inheritance and polymorphism work in C++,
how to manage dynamic memory properly, how to identify object types at runtime, 
and how to handle pointers and references safely.
*/