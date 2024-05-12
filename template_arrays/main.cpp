#include "template_array.h"

using namespace std;

int main(){
    MyArr<double, 12> array( 5 );
    cout << array[3] << endl;

    MyArr<int, 10> sums;
    MyArr<double, 10> aves;
    MyArr< MyArr<int, 5>, 10> twodee;

    for( int i = 0; i < 10; i++ ){
        sums[i] = 0;
        for( int j = 0; j < 5; j++ ){
            twodee[i][j] = ( i + 1 ) * ( j + 1 );
            sums[i] += twodee[i][j];
        }
        aves[i] = ( double ) sums[i] / 5;
    }

    for( int i = 0; i < 10; i++ ){
        for( int j = 0; j < 5; j++ ){
            cout.width( 2 );
            cout << twodee[i][j] << " ";
        }
        cout << "suma: ";
        cout.width( 3 );
        cout << sums[i] << ", aver: ";
        cout.width( 3 );
        cout << aves[i] << endl;
    }
}