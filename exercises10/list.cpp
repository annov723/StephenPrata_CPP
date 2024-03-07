#include "list.h"

#include <iostream>

using namespace std;


 Node::Node(){
    data = NULL;
    next = NULL;
}
Node::Node( void *data ){
    this->data = data;
    next = NULL;
}

void Node::print( char c ){
    if( data == NULL ){
        cout << "pusty!" << endl;
        return;
    }
    switch( c ){
        case 'i': 
            cout << *reinterpret_cast<int*>( data ) << endl;
            break;
        case 'd': 
            cout << *reinterpret_cast<double*>( data ) << endl; 
            break;
        case 'c': 
            cout << *reinterpret_cast<char*>( data ) << endl;
            break;
        case 's': 
            cout << *reinterpret_cast<string*>( data ) << endl;
            break;
        defeult:
            cout << "invalid type!" << endl;
    }
}

List::List(){
    head = NULL;
    max = 10;
}

List::List( int max ){
    head = NULL;
    this->max = max;
}

List::List( void *data, int max ){
    Node *newN = new Node( data );
    head = newN;
    this->max = max;
    count = 1;
}

void List::add( void *data ){
    if( is_full() ) return;

    if( head == NULL ){
        Node *newN = new Node( data );
        head = newN;
        count++;
        return;
    }

    Node *curr = head;
    while( curr->next != NULL ) curr = curr->next;
    Node *newN = new Node( data );
    curr->next = newN;
    count++;
}

bool List::is_empty(){
    if( head == NULL ) return true;
    return false;
}

bool List::is_full(){
    if( count == max ) return true;
    return false;
}

const void* List::get_data( int n ){
    if( n < 1 || n > count ) return NULL;

    Node *curr = head;
    for( int i = 1; i < n; i++ ) curr = curr->next;
    const void *ptr = curr->data;
    return ptr;  
}

void List::remove(){
    Node *curr = head;
    Node *last;
    while( curr->next != NULL ){
        last = curr;
        curr = curr->next;
    }

    last->next = NULL;
    delete curr;
    count--;

}

void List::print( char c ){
    Node *curr = head;
    while( curr != NULL ){
        curr->print( c );
        curr = curr->next;
    }
}

List::~List(){
    if( head == NULL ) return;

    Node *curr = head;
    Node *del;
    while( curr->next != NULL ){
        del = curr;
        curr = curr->next;
        delete del;
    }
    delete curr;
}