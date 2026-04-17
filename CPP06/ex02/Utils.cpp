#include "Utils.hpp"

int seedflag = 0;

Base* generate(void){
    if (seedflag == 0){
        srand(static_cast<unsigned int>(time(NULL)));
        seedflag = 1;
    }
    int num = rand();
    int result = num % 3;
    Base* randABC = (result == 0) ? static_cast<Base*>(new A) 
    : (result == 1) ? static_cast<Base*>(new B) 
    : static_cast<Base*>(new C); // just for some new thing..
    return randABC;
}


void identify(Base* p){
    if (!p){
        std::cout << "WHO AM I: IM JUST A NUL PERSONNE\n";
        return ;
    }
    // if (dynamic_cast<A*>(p) != nullptr) this is c++11 
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "who am i: A as Apple\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "who am i: B as Badger\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "who am i: C as Clear water\n";
}


void identify(Base& p){
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "ref me: A\n";
    }
    catch(std::exception &e){
    }
    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "ref me: B\n";
    }
    catch(std::exception &e){
    }
    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "ref me: C\n";
    }
    catch(std::exception &e){
    }

}

// It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.

// It prints the actual type of the object pointed to by p: "A", "B", or "C".

// It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
// inside this function is forbidden.