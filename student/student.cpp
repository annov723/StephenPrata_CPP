#include "student.h"

double Student::Average() const{
    if( Arr::size() > 0 ) return Arr::sum() / Arr::size();
    return 0;
}

const string& Student::Name() const{
    return ( const string& ) *this;
}

double& Student::operator[]( int i ){
    return Arr::operator[]( i );
}

double Student::operator[]( int i ) const{
    return Arr::operator[]( i );
}



ostream& Student::arr_out( ostream &os ) const{
    int i;
    int lim = Arr::size();
    if( lim > 0 ){
        for( i = 0; i < lim; i++ ){
            os << Arr::operator[]( i ) << " ";
            if( i % 5 == 4 ) os << endl;
        }
        if( i % 5 != 0 ) os << endl;
    }
    else os << "brak wynikow";
    return os;
}



istream& operator>>( istream &is, Student &stu ){
    is >> ( string& ) stu;
    return is;
}

istream& getline( istream &is, Student &stu ){
    getline( is, ( string& ) stu );
    return is;
}

ostream& operator<<( ostream &os, Student &stu ){
    os << "Wyniki " << ( const string& ) stu << endl;
    stu.arr_out( os );
    return os;
}