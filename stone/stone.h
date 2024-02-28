#ifndef __STONE__
#define __STONE__

#include <iostream>

class Stone{
private:
    enum { ibs_stn = 14 }; //liczba funtów na kamień
    int stone;  //masa w całych kamieniach
    double pds_left; //reszta w funtach
    double pds; //masa w funtach

public:
    Stone( double ibs );
    Stone( int stn, double ibs );
    Stone();
    ~Stone();

    void show_ibs() const;
    void show_stn() const;

    operator int() const;
    operator double() const;
    Stone operator+( const Stone & b ) const;
    
};

#endif