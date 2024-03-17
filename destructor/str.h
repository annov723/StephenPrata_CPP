#ifndef __STR__
#define __STR__

#include <iostream>

class Str{
private:
    char *str;
    int len;
    static int num_strings;
    static const int MAX = 80;

public:
    Str();
    Str( const char *s );
    Str( const Str &s ); //jawny konstruktor kopiujący
    ~Str();

    int lenght() const { return len; }

    Str& operator=( const Str &s );
    Str& operator=( const char* s );
    char& operator[]( int i );
    const char& operator[]( int i ) const; //specjalnie dla obiektów, które są const
    static int HowMany(){ return num_strings; } //można też zadeklarować funkcję w pliku str.cpp

    friend std::ostream& operator<<( std::ostream &os, const Str &a );
    friend std::istream& operator>>( std::istream &is, Str &s );
    friend bool operator<( const Str &s1, const Str &s2 );
    friend bool operator>( const Str &s1, const Str &s2 );
    friend bool operator==( const Str &s1, const Str &s2 );


};

#endif