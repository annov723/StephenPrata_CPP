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

List::List(){
    head = NULL;
    max = 10;
}

List::List( int max ){
    head = NULL;
    this->max = max;
}

List::List( void *data, int max ){
    head->data = data;
    head->next = NULL;
    this->max = max;
    count = 1;
}

void List::add( void *data ){
    if( is_full() ) return;
    if( head == NULL ){
        head->data = data;
        head->next = NULL;
        count++;
        return;
    }
    Node *curr = head;
    while( curr->next != NULL ) curr = curr->next;
    Node *newN = new Node( data );
    curr->next = newN;
    newN->next = NULL;
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

void* List::get_data( int n ){
    if( n < 1 || n > count ) return NULL;

    Node *curr = head;
    for( int i = 1; i < n; i++ ) curr = curr->next;

    
}

void List::remove(){

}

List::~List(){
    Node *curr = head;
    Node *del;
    while( curr->next != NULL ){
        del = curr;
        curr = curr->next;
        delete del;
    }
}