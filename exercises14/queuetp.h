#include <iostream>

using namespace std;

#define SIZE 2



template<typename T>
class MyQueue{
private:
    int capacity;
    int howMany;
    T* queueQ;
    T* start;

public:
    MyQueue( int c = SIZE ) : capacity( c ), howMany( 0 ){
        queueQ = new T[capacity];
        start = queueQ;
    }
    ~MyQueue() { delete [] start; }

    bool isFull() { return howMany == capacity; }
    bool isEmpty() { return howMany == 0; }

    void enqueue( T a ){
        if( isFull() ) return;
        queueQ[howMany++] = a;
    }

    T dequeue(){
        if( isEmpty() ) return NULL;
        T ptr = queueQ[0];
        queueQ = &queueQ[1];
        return ptr;
    }

    T operator[]( int n ){
        return queueQ[n];
    }

};