#ifndef __ZESP__
#define __ZESP__

#include <iostream>

class Zesp{
private:
    double rzecz;
    double uro;

public:
    Zesp();
    Zesp( double n1, double n2 );

    void set_rzecz( double n ){ rzecz = n; }
    void set_uro( double n ){ uro = n; }

    double get_rzecz() const { return rzecz; }
    double get_uro() const { return uro; }

    Zesp operator~() const;
    Zesp operator+( const Zesp & b ) const;
    Zesp operator-( const Zesp & b ) const;
    Zesp operator*( const Zesp & b ) const;

    friend std::ostream & operator<<( std::ostream & os, const Zesp & b );
    friend std::istream & operator>>( std::istream & is , Zesp & b );
    friend Zesp operator*( double d, const Zesp & b );
};

#endif