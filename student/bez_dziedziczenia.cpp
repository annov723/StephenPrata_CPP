//#include "student.h"
//wersja bez dziedziczenia wielokrotnego

double Student::Average() const{
    if( scores.size() > 0 ) return scores.sum() / scores.size();
}

const string& Student::Name() const{
    return name;
}

double& Student::operator[]( int i ){
    return scores[i];
}

double Student::operator[]( int i ) const{
    return scores[i];
}



ostream& Student::arr_out( ostream &os ) const{
    int i;
    int lim = scores.size();
    if( lim > 0 ){
        for( i = 0; i < lim; i++ ){
            os << scores[i] << " ";
            if( i % 5 == 4 ) os << endl;
        }
        if( i % 5 != 0 ) os << endl;
    }
    else os << "brak wynikow";
    return os;
}



istream& operator>>( istream &is, Student &stu ){
    is >> stu.name;
    return is;
}

istream& getline( istream &is, Student &stu ){
    getline( is, stu.name )
    return is;
}

ostream& operator<<( ostream &os, Student &stu ){
    os << "Wyniki " << stu.name << endl;
    stu.arr_out( os );
    return os;
}