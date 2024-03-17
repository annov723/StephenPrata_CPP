#include "str.h"

#include <cstring>

using std::cout, std::endl, std::cin;

int Str::num_strings = 0; //inicjalizacja statycznej składowej klasy

Str::Str(){
    len = 0;
    str = new char[1]; //można usunąć delete [] str
    //str = 0; określa wzkaźnik pusty, który można usunąć delete [] str
    str[0] = '\0';
    num_strings++;
}

Str::Str( const char *s ){
    len = std::strlen( s );
    str = new char[len + 1];
    std::strcpy( str, s );
    num_strings++;
}

Str::Str( const Str &s ){
    num_strings++;
    len = s.len;
    str = new char[ len + 1];
    std::strcpy( str, s.str );
}

Str::~Str(){
    num_strings--;
    cout << "Sa jeszcze: " << num_strings << endl;
    delete [] str;
}



Str& Str::operator=( const Str &s ){
    if( this == &s ) return *this;

    delete [] str;
    len = s.len;
    str = new char[len + 1];
    std::strcpy( str, s.str );
    return *this;
}

Str& Str::operator=( const char* s ){
    delete [] str;
    len = std::strlen( s );
    str = new char[len + 1];
    std::strcpy( str, s );
    return *this;
}

char& Str::operator[]( int i ){
    return str[i];
}

const char& Str::operator[]( int i ) const{
    return str[i];
}



std::ostream& operator<<( std::ostream &os, const Str &a ){
    os << a.num_strings << ": " << a.str;
    return os;
}

std::istream& operator>>( std::istream &is, Str &s ){
    char temp[Str::MAX]; //odwołania do stałych w klasie
    is.get( temp, Str::MAX );

    if( is ) s = temp; //używamy overloading przypisującego do obiektu klasy nowy łańcuch

    while( is && is.get() != '\n' ) continue; //czyścimy buffor
    return is;
}

bool operator<( const Str &s1, const Str &s2 ){
    return ( std::strcmp( s1.str, s2.str ) < 0 );
}

bool operator>( const Str &s1, const Str &s2 ){
    return ( s2.str < s1.str );
}

bool operator==( const Str &s1, const Str &s2 ){
    return( std::strcmp( s1.str, s2.str ) == 0 );
}