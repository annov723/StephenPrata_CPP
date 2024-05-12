#include "stacktp.h"

template<typename Type>
Stack<Type>::Stack( int ss ) : stackSize( ss ), top( 0 ) {
    items = new Type[stackSize];
}

template<typename Type>
Stack<Type>::Stack( const Stack& s ){
    stackSize = s.stackSize;
    top = s.top;
    items = new Type[stackSize];

    for( int i = 0; i < top; i++ ) items[i] = s.items[i];
}

template<typename Type>
bool Stack<Type>::isEmpty(){
    return top == 0;
}

template<typename Type>
bool Stack<Type>::isFull(){
    return top == stackSize;
}

template<typename Type>
bool Stack<Type>::push( const Type& item ){
    if( top >= MAX ) return false;

    items[top++] = item;
    return true;
    
}

template<typename Type>
bool Stack<Type>::pop( Type& item ){
    if( top == 0 ) return false;

    item = items[--top];
    return true; 
}

template<typename Type>
Stack<Type>& Stack<Type>::operator=( const Stack<Type>& s ){
    if( this == &s ) return *this;

    delete []items;

    stackSize = s.stackSize;
    top = s.top;
    items = new Type[stackSize];

    for( int i = 0; i < top; i++ ) items[i] = s.items[i];
    return *this;
}
