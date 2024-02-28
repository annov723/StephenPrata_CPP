#include "vector.h"

#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::atan2;
using std::cos;

namespace VECTOR{

    const double rad_to_deg = 57.2957795130823;

    void Vector::set_length(){
        length = sqrt( x * x + y * y );
    }

    void Vector::set_angle(){
        if( x == 0.0 && y == 0.0 ) angle = 0.0;
        else angle = atan2( y, x );
    }

    void Vector::set_x(){
        x = length * cos( angle );
    }

    void Vector::set_y(){
        y = length * sin( angle );
    }



    Vector::Vector(){
        x = y = length = angle = 0.0;
        mode = 'r';
    }

    Vector::Vector( double n1, double n2, char form ){
        mode = form;

        if( mode == 'r' ){
            x = n1;
            y = n2;
            set_length();
            set_angle();
        }
        else if( mode == 'p' ){
            length = n1;
            angle = n2 / rad_to_deg;
            set_x();
            set_y();
        }
        else{
            cout << "Niepoprawna wartość trzeciego argumentu!" << endl;
            cout << "Wektor zostanie wyzerowany." << endl;
            x = y = length = angle = 0.0;
            mode = 'r';
        }
    }

    Vector::~Vector(){

    }



    void Vector::set( double n1, double n2, char form ){
        mode = form;

        if( mode == 'r' ){
            x = n1;
            y = n2;
            set_length();
            set_angle();
        }
        else if( mode == 'p' ){
            length = n1;
            angle = n2 / rad_to_deg;
            set_x();
            set_y();
        }
        else{
            cout << "Niepoprawna wartość trzeciego argumentu!" << endl;
            cout << "Wektor zostanie wyzerowany." << endl;
            x = y = length = angle = 0.0;
            mode = 'r';
        }
    }

    void Vector::polar_mode(){
        mode = 'p';
    }

    void Vector::rect_mode(){
        mode = 'r';
    }



    Vector Vector::operator+( const Vector & b ) const{
        return Vector( x - b.x, y - b.y );
    }

    Vector Vector::operator-( const Vector & b ) const{
        return Vector( x - b.x, y - b.y );
    }

    Vector Vector::operator-() const{
        return Vector( -x, -y );
    }

    Vector Vector::operator*( double n ) const{
        return Vector( x * n, y * n );
    }



    Vector operator*( double a, const Vector & b ){
        return b * a;
    }

    std::ostream & operator<<( std::ostream & os, const Vector & b ){
        if( b.mode == 'r' ) os << "(x, y) = (" << b.x << ", " << b.y << ")"; 
        else if( b.mode == 'p' ) os << "(len, ang) = (" << b.length << ", " << b.angle << ")";
        else{
            cout << "Niepoprawny tryb reprezentacji wektora!" << endl;
        }
        return os;
    }

}