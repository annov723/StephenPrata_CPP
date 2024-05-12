#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T, int n>
class MyArr{
private:
    T ar[n];

public:
    MyArr() {}
    explicit MyArr( const T& v );
    virtual T& operator[]( int i );
    virtual T operator[]( int i ) const;
};

template<typename T, int n>
MyArr<T, n>::MyArr( const T& v ){
    for( int i = 0; i < n; i++ ) ar[i] = v;
}

template<typename T, int n>
T& MyArr<T, n>::operator[]( int i ){
    if( i < 0 || i >= n ){
        cerr << "Zla wartosc!" << endl;
        exit( EXIT_FAILURE );
    }
    return ar[i];
}

template<typename T, int n>
T MyArr<T, n>::operator[]( int i ) const{
    if( i < 0 || i >= n ){
        cerr << "Zla wartosc!" << endl;
        exit( EXIT_FAILURE );
    }
    return ar[i];
}



int main(){
    MyArr<double, 12> array( 5 );
    cout << array[3] << endl;
}