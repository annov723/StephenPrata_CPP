#include "vector.h"

#include <cstdlib> //rand() i srand()
#include <ctime> //time()

int main(){
    using namespace std;
    using VECTOR::Vector; //zezwalamy na używanie klasy Vector

    srand( time( 0 ) );
    double direction;
    Vector step;
    Vector result( 0.0, 0.0 );
    unsigned long steps = 0;
    double target;
    double dstep;

    cout << "Podaj dystans do przejscia (k, aby zakonczyc): ";
    while( cin >> target ){
        cout << "Podaj dlugosc kroku: ";
        if( !( cin >> dstep ) ) break;

        while( result.lengthval() < target ){
            direction = rand() % 360;
            step.set( dstep, direction, 'p' );
            result = result + step;
            steps++;
        }

        cout << "Po przejsciu " << steps << " krokow osiagnieto polozenie: ";
        cout << result;

        result.polar_mode();
        cout << ", czyli " << result << "." << endl;

        cout << "srednia dlugosc kroku = " << result.lengthval() / steps << endl;
        steps = 0;
        result.set( 0.0, 0.0 ); //automatycznie zmienia na 'r' mode

        cout << "Podaj dystans do przejscia (k, aby zakonczyc): ";
    }

    return 0;
}