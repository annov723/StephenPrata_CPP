#include "list.h"

#include <iostream>

using namespace std;



int main(){
    int *a = new int( 3 );
    string *s1 = new string( "bob" );
    string *s2 = new string( "bobek" );

    Node n1;
    Node n2( a );
    n1.print( 'i');
    n2.print( 'i' );

    cout << endl;

    List list1;
    List list2( 2 );
    List list3( s1 );
    List list4( s2, 3 );

    list1.print( 'i' );
    list2.print( 'd' );
    list3.print( 's' );
    list4.print( 's' );

    cout << "### LIST I ###" << endl;

    cout << list1.is_empty() << endl;
    int *b = new int( 4 );
    int *c = new int( 5 );
    list1.add( a );
    list1.add( b );
    list1.add( c );
    cout << list1.is_full() << endl;
    list1.print( 'i' );

    cout << "### LIST II ###" << endl;

    cout << list2.is_empty() << endl;
    list2.add( a );
    list2.add( b );
    list2.add( c );
    cout << list2.is_full() << endl;
    list2.print( 'i' );

    cout << "### LIST III ###" << endl;

    cout << list3.is_empty() << endl;
    list3.add( s1 );
    list3.add( s2 );
    cout << list3.is_full() << endl;
    list3.print( 's' );
    list3.remove();
    cout << endl;
    list3.print( 's' );

    cout << "### LIST IV ###" << endl;

    cout << list4.is_empty() << endl;
    list4.add( s1 );
    list4.add( s2 );
    cout << list4.is_full() << endl;
    list4.print( 's' );
    list4.remove();
    cout << endl;
    list4.print( 's' );
    cout << endl;
    cout << list4.is_full() << endl;
    list4.add( s2 );
    list4.add( s2 );
    list4.print( 's' );

    delete a;
    delete b;
    delete c;
    delete s1;
    delete s2;

    return 0;
}