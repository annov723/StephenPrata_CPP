#include "stone.h"

using std::cout;
using std::endl;

Stone::Stone( double ibs ){
    stone = ( int ) ibs / ibs_stn;
    pds_left = int( ibs ) % ibs_stn + ibs - int( ibs ); //reszta z dzielenia + część po przecinku
    pds = ibs;
}

Stone::Stone( int stn, double ibs ){
    stone = stn;
    pds_left = ibs;
    pds = stn * ibs_stn + ibs;
}

Stone::Stone(){
    stone = pds = pds_left = 0;
}

Stone::~Stone(){

}



void Stone::show_ibs() const{
    cout << pds << " funtów." << endl;
}

void Stone::show_stn() const{
    cout << stone << " kamieni, " << pds_left << " funtów." << endl;
}



Stone::operator int() const{
    return int( pds + 0.5 ); //int zaokrągla w dół, więc tylko jak początkowo było więcej niż 0.5 to tak jakby zaokrągli do góry
}

Stone::operator double() const{
    return pds;
}

Stone Stone::operator+( const Stone & b ) const{
    double p = pds + b.pds;
    Stone sum( p );
    return sum;
}