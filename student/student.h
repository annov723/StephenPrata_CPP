#ifndef __STUDENT__
#define __STUDENT__

#include <iostream>
#include <string>
#include <valarray>

using namespace std;

class Student : private string, private valarray<double>{ //dziedziczenie wielokrotne
private:
    typedef valarray<double> Arr; //podmieniamy każdą nazwę Arr na valarray
    //string name;
    //Arr scores;
    ostream& arr_out( ostream &os ) const;

    //using std::valarray<double>::min; - i wtedy możemy pisać samo "min"

public:
    /*konstruktory metoda inline
    Student() : name( "brak" ), scores() {}
    Student( const string &s ) : name( s ), scores() {}
    explicit Student ( int n ) : name( "brak" ), scores( n ) {} //nie pozwoli na przypisanie liczby do obiektu, np. bob = 5!
    Student( string &s, int n ) : name( s ), scores( n ) {} //n - ile elementów ma mieć tablica
    Student( const string &s, const Arr &a ) : name( s ), scores( a ) {}
    Student( const char *str, const double *pd, int n ) : name( str ), scores( pd, n ) {} //wywołuje konstruktor dla valarray: valarray<double>( const double*, int )
    //lista inicjalizacyjna powoduje, że obiekty składowe tworzone są przed inicjalizacją pozostałych danych (żeby kompilator nie użył konsturktorów domyślnych dla obiektów)
    //kolejność inicjalizacji składowych ma znaczenie*/

    //konstruktory dla dziedziczenia wielokrotnego - nazwy klas zamiast nazw składowych
    Student() : string( "brak" ), Arr() {}
    Student( const string &s ) : string( s ), Arr() {}
    Student ( int n ) : string( "brak" ), Arr( n ) {} //nie pozwoli na przypisanie liczby do obiektu, np. bob = 5!
    Student( string &s, int n ) : string( s ), Arr( n ) {} //n - ile elementów ma mieć tablica
    Student( const string &s, const Arr &a ) : string( s ), Arr( a ) {}
    Student( const char *str, const double *pd, int n ) : string( str ), Arr( pd, n ) {} //wywołuje konstruktor dla valarray: valarray<double>( const double*, int )
    ~Student() {}

    double Average() const;
    const string& Name() const;
    double& operator[]( int i );
    double operator[]( int i ) const;

    friend istream& operator>>( istream &is, Student &stu ); //1 wyraz
    friend istream& getline( istream &is, Student &stu ); //cała linia
    friend ostream& operator<<( ostream &os, Student &stu );
};

#endif