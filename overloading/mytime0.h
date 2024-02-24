#ifndef __MYTIME0_H__
#define __MYTIME0_H__

class Time{
private:
    int hours;
    int minutes;

public:
    Time();
    Time( int h, int m );
    void AddM( int m );
    void AddH( int h );
    void Reset( int h = 0, int m = 0 ); //tylko w pliku h dodajemy bazowe wartości zmiennych funkcji
    Time operator+( const Time & t ) const;
    Time operator-( const Time & t ) const;
    Time operator*( double n ) const;
    void Show() const;

    int getH() const;
    int getM() const;

};

#endif