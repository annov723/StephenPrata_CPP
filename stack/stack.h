#ifndef __STACK__
#define __STACK__

typedef unsigned long Item;



class Stack{
private:
    enum { MAX = 10 }; //zamiennik dla deklaracji stałej, która jest w klasie niedostępna
    Item items[MAX];
    int top;

public:
    Stack();
    bool isempty() const;
    bool isfull() const;

    bool push( const Item &item );
    bool pop( Item &item );
    void show();

};

#endif