#include "stacktp.h"


template<typename Type>
Stack<Type>::Stack(){
    top = 0;
}

template<typename Type>
bool Stack<Type>::isEmpty(){
    return top == 0;
}

template<typename Type>
bool Stack<Type>::isFull(){
    return top == MAX;
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
