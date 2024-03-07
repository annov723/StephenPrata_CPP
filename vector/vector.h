#ifndef __VECTOR__
#define __VECTOR__

#include <iostream>

namespace VECTOR{

    class Vector{
    private:
        double x;
        double y;
        double length;
        double angle;
        char mode; // 'r' - prostokątny, 'p' - biegunowy, składowa stanu (wpływa na wywołanie poszczególnych funkcji)

        void set_length();
        void set_angle();
        void set_x();
        void set_y();

    public:
        Vector();
        Vector( double n1, double n2, char form = 'r' );
        ~Vector();

        void set( double n1, double n2, char form = 'r' );
        double xval() const { return x; }
        double yval() const { return y; }
        double lengthval() const { return length; }
        double angleval() const { return angle; }
        void polar_mode();
        void rect_mode();

        Vector operator+( const Vector & b ) const;
        Vector operator-( const Vector & b ) const;
        Vector operator-() const;
        Vector operator*( double n ) const;

        friend Vector operator*( double a, const Vector & b );
        friend std::ostream & operator<<( std::ostream & os, const Vector & b );

    };
}

#endif