#ifndef __STACK__
#define __STACK__

#include <iostream>

template<typename Type>
class Stack{
private:
    enum{ MAX = 3 };
    Type items[MAX];
    int top;

public:
    Stack();
    bool isEmpty();
    bool isFull();
    bool push( const Type& item );
    bool pop( Type& item );

};

#endif