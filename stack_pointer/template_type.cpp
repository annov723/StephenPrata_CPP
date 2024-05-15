#include "stacktp.h"
#include "stacktp.cpp"

using namespace std;

template<template<typename T> typename Type, typename U, typename V>
class Crab{
private:
    Type<U> s1; //obiekt typu Type, który używa template i w tym obiekcie template ma typ T
    Type<V> s2;

public:
    Crab(){}
    bool push( int a, double x ){
        return s1.push( a ) && s2.push( x );
    }

    bool pop( int& a, double& x ){
        return s1.pop( a ) && s2.pop( x );
    }

};

int main(){
    Crab<Stack, int, double> bob;
    int n; 
    double d;

    cout << "Podaj pary int i double, np. 3 2.3 (0 0 kończy program):" << endl;
    while( cin >> n >> d && n != 0 && d != 0 ){
        if( !bob.push( n, d ) ) break;
    }

    while( bob.pop( n, d ) ) cout << n << " " << d << endl;
}