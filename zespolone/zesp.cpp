#include "zesp.h"

using std::cout;
using std::cin;

Zesp::Zesp(){
    rzecz = uro = 0;
}

Zesp::Zesp( double n1, double n2 ){
    rzecz = n1;
    uro = n2;
}



Zesp Zesp::operator~() const{
    Zesp val( rzecz, -uro );
    return val; 
}

Zesp Zesp::operator+( const Zesp & b ) const{
    Zesp val( rzecz + b.rzecz, uro + b.uro );
    return val;
}

Zesp Zesp::operator-( const Zesp & b ) const{
    Zesp val( rzecz - b.rzecz, uro - b.uro );
    return val;
}

Zesp Zesp::operator*( const Zesp & b ) const{
    double b1 = rzecz * b.rzecz - uro * b.uro;
    double b2 = rzecz * b.uro + uro * b.rzecz;
    Zesp val( b1, b2 );
    return val;
}



std::ostream & operator<<( std::ostream & os, const Zesp & b ){
    os << "(" << b.get_rzecz() << "," << b.get_uro() << "i)";
    return os;
}

std::istream & operator>>( std::istream & is , Zesp & b ){
    double n1, n2;
    cout << "\nskladowa rzeczywista: ";
    if ( !( is >> n1 ) ) return is;
    cout << "skladowa urojona: ";
    is >> n2;
    b.set_rzecz( n1 );
    b.set_uro( n2 );
    return is;
}

Zesp operator*( double d, const Zesp & b ){
    Zesp val( b.rzecz * d, b.uro * d );
    return val;
}