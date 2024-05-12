#ifndef __STACK__
#define __STACK__

#include <iostream>

template<typename Type>
class Stack{
private:
    enum{ MAX = 3 };
    int stackSize; //rozmiar domyslny
    Type* items;
    int top;

public:
    explicit Stack( int ss = MAX ); //ten konstruktor nie będzie konwertował typów żeby dopasować do oczekiwanego
    Stack( const Stack& s );
    ~Stack(){ delete []items; }

    bool isEmpty();
    bool isFull();
    bool push( const Type& item );
    bool pop( Type& item );

    Stack& operator=( const Stack& s );

};

#endif