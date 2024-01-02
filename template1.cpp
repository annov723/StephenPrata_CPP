#include <iostream>
#include <vector>

using namespace std;

template <class Any>
void Swap( Any &a, Any &b );

template<class Any>
void Swap( Any *a, Any *b, int n );

int main( void ){
    int i = 10, j = 20;
    cout << "Before the Swap: i = " << i << ", j = " << j << endl;
    Swap( i, j );
    cout << "After the Swap: i = " << i << ", j = " << j << endl;

    string c = "bob", d = "pup";
    cout << "Before the Swap: c = " << c << ", d = " << d << endl;
    Swap( c, d );
    cout << "After the Swap: c = " << c << ", d = " << d << endl;

    vector<int> a;
    vector<int> b;
    for( int i = 0; i < 5; i++ ){
        a.push_back( i );
        b.push_back( 4 - i );
    }
    cout << "Before the Swap:" << endl;
    for( auto i : a ) cout << i << " ";
    cout << endl;
    for( auto i : b ) cout << i << " ";
    cout << endl;
    Swap( a, b );
    cout << "After the Swap:" << endl;\
    for( auto i : a ) cout << i << " ";
    cout << endl;
    for( auto i : b ) cout << i << " ";
    cout << endl;

    return 0;
}

template <class Any>
void Swap( Any &a, Any &b ){
    Any temp;
    temp = a;
    a = b;
    b = temp;
}

template<class Any>
void Swap( Any a[], Any b[], int n ){
    Any temp;
    for( int i = 0; i < n; i++ ){
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}