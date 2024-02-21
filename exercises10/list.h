#ifndef __LIST__
#define __LIST__



class Node{
public:
    void *data;
    Node *next;

    Node();
    Node( void *data );
    void print( char c );
};

class List{
private:
    Node *head;
    int max;
    int count = 0;

public:
    List();
    List( int max );
    List( void *data, int max = 10 );

    void add( void *data );
    bool is_empty();
    bool is_full();
    const void* get_data( int n );
    void remove();

    void print( char c );

    ~List();

};

#endif